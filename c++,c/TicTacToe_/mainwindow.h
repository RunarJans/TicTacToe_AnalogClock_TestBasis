#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonClicked();      // Slot voor de button click events
    void on_resetButton_clicked(); // Slot voor de reset button

private:
    Ui::MainWindow *ui;
    QString currentPlayer;
    void updateStatusLabel(const QString &message); // Functie om de status van de speler te updaten
    bool checkWin();  // Functie om te controleren of er een winnaar is
    bool checkDraw(); // Functie om te controleren of er een gelijkspel is
};

#endif // MAINWINDOW_H
