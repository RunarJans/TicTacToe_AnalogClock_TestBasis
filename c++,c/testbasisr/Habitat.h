#include "Dier.h"
#include <iostream>
#include <memory> // Voor unique_ptr

class Habitat {
public:
    // Gebruik van unique_ptr om automatisch geheugenbeheer te faciliteren
    Habitat(std::unique_ptr<Dier> dier) : bewoner(std::move(dier)) {}

    void geluidVanBewoner() const {
        bewoner->geluidMaken();
    }

private:
    std::unique_ptr<Dier> bewoner;  // De pointer naar Dier wordt beheerd door unique_ptr
};
