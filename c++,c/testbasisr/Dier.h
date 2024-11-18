#pragma once

// Dier is een abstracte basisklasse die de interface definieert voor alle dieren
class Dier {
public:
    virtual void geluidMaken() const = 0; // Pure virtuele functie, zorgt voor abstractie
    virtual ~Dier() = default;            // Virtual destructor voor veilige destructie
};

