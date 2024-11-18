#pragma once
#include "Dier.h"
#include <iostream>

class Vogel : public Dier {
public:
    virtual ~Vogel() = default;

    void geluidMaken() const override {
        std::cout << "Vogel maakt geluid." << std::endl;
    }
};

class Papegaai : public Vogel {
public:
    void geluidMaken() const override {
        std::cout << "Papegaai zegt: 'Hallo!'" << std::endl;
    }
};

class Duif : public Vogel {
public:
    void geluidMaken() const override {
        std::cout << "Duif maakt coo geluid." << std::endl;
    }
};
