#pragma once
#include "Dier.h"
#include <iostream>

class Zoogdier : public Dier {
public:
    virtual ~Zoogdier() = default;

    void geluidMaken() const override {
        std::cout << "Zoogdier maakt geluid." << std::endl;
    }
};

class Leeuw : public Zoogdier {
public:
    void geluidMaken() const override {
        std::cout << "Leeuw brult!" << std::endl;
    }
};

class Aap : public Zoogdier {
public:
    void geluidMaken() const override {
        std::cout << "Aap maakt geluid: 'Oe-oe, ah-ah!'" << std::endl;
    }
};
