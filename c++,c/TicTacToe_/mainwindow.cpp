#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentPlayer("X") // Speler X begint
{
    ui->setupUi(this);

    // Stel de status in bij het starten van het spel
    updateStatusLabel("Player X's turn");

    // Verbind de button kliks met de bijbehorende functie
    connect(ui->button1, &QPushButton::clicked, this, &MainWindow::on_buttonClicked);
    connect(ui->button2, &QPushButton::clicked, this, &MainWindow::on_buttonClicked);
    connect(ui->button3, &QPushButton::clicked, this, &MainWindow::on_buttonClicked);
    connect(ui->button4, &QPushButton::clicked, this, &MainWindow::on_buttonClicked);
    connect(ui->button5, &QPushButton::clicked, this, &MainWindow::on_buttonClicked);
    connect(ui->button6, &QPushButton::clicked, this, &MainWindow::on_buttonClicked);
    connect(ui->button7, &QPushButton::clicked, this, &MainWindow::on_buttonClicked);
    connect(ui->button8, &QPushButton::clicked, this, &MainWindow::on_buttonClicked);
    connect(ui->button9, &QPushButton::clicked, this, &MainWindow::on_buttonClicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::on_resetButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateStatusLabel(const QString &message) {
    ui->statusLabel->setText(message);  // Stel de status van de speler in de label in
}

bool MainWindow::checkWin() {
    // Horizontale lijnen controleren
    if (ui->button1->text() == ui->button2->text() && ui->button2->text() == ui->button3->text() && !ui->button1->text().isEmpty()) {
        return true;
    }
    if (ui->button4->text() == ui->button5->text() && ui->button5->text() == ui->button6->text() && !ui->button4->text().isEmpty()) {
        return true;
    }
    if (ui->button7->text() == ui->button8->text() && ui->button8->text() == ui->button9->text() && !ui->button7->text().isEmpty()) {
        return true;
    }

    // Verticale lijnen controleren
    if (ui->button1->text() == ui->button4->text() && ui->button4->text() == ui->button7->text() && !ui->button1->text().isEmpty()) {
        return true;
    }
    if (ui->button2->text() == ui->button5->text() && ui->button5->text() == ui->button8->text() && !ui->button2->text().isEmpty()) {
        return true;
    }
    if (ui->button3->text() == ui->button6->text() && ui->button6->text() == ui->button9->text() && !ui->button3->text().isEmpty()) {
        return true;
    }

    // Diagonalen controleren
    if (ui->button1->text() == ui->button5->text() && ui->button5->text() == ui->button9->text() && !ui->button1->text().isEmpty()) {
        return true;
    }
    if (ui->button3->text() == ui->button5->text() && ui->button5->text() == ui->button7->text() && !ui->button3->text().isEmpty()) {
        return true;
    }

    return false; // Geen winnaar
}


bool MainWindow::checkDraw() {
    // Controleer of alle knoppen zijn ingedrukt en er geen winnaar is
    for (int i = 1; i <= 9; ++i) {
        QPushButton *button = findChild<QPushButton *>(QString("button%1").arg(i));
        if (button && button->text().isEmpty()) {
            return false; // Als er nog een lege knop is, is het geen gelijkspel
        }
    }
    return true; // Als er geen lege knoppen zijn, is het een gelijkspel
}

void MainWindow::on_buttonClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    // Debug: Controleer de knopnaam die is aangeklikt
    qDebug() << "Button " << button->objectName() << " clicked by " << currentPlayer;

    if (button && button->text().isEmpty()) {
        button->setText(currentPlayer);

        // Controleer of iemand gewonnen heeft
        if (checkWin()) {
            qDebug() << "Winner found: " << currentPlayer;
            updateStatusLabel(QString("%1 wins!").arg(currentPlayer));
            return;
        } else if (checkDraw()) {
            qDebug() << "Game is a draw.";
            updateStatusLabel("It's a draw!");
            return;
        } else {
            // Wissel van speler
            currentPlayer = (currentPlayer == "X") ? "O" : "X";
            updateStatusLabel(QString("Player %1's turn").arg(currentPlayer));
        }
    }
}





void MainWindow::on_resetButton_clicked() {
    // Reset alle knoppen naar leeg
    for (int i = 0; i < 9; ++i) {
        QPushButton *button = findChild<QPushButton *>(QString("button%1").arg(i + 1));
        if (button) {
            button->setText("");
        }
    }

    // Stel de eerste speler in (X) en update de status
    currentPlayer = "X";
    updateStatusLabel("Player X's turn");
}
