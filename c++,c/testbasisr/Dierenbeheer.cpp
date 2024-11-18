#include "Vogel.h"
#include "Zoogdier.h"
#include <iostream>

int main() {
    // Specifieke diersoorten gebruiken in plaats van generieke 'Vogel' en 'Zoogdier'
    Leeuw leeuw;
    Aap aap;
    Papegaai papegaai;
    Duif duif;

    leeuw.geluidMaken();
    aap.geluidMaken();
    papegaai.geluidMaken();
    duif.geluidMaken();

    return 0;
}
