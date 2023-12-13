#pragma once

#include <iostream>
#include <string>

class horaire
{
private:
    unsigned int _mois;
    unsigned int _jour;
    unsigned int _heure;

public:
    // Constructeur
    horaire(int const &mois, int const &jour, int const &heure);

    // Accesseurs
    unsigned int mois() const { return _mois; }
    unsigned int jour() const { return _jour; }
    unsigned int heure() const { return _heure; }

    std::string tostring() const;
};
