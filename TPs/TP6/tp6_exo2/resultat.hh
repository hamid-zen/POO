#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

using liste_entiers = std::vector<unsigned int>;

class resultat
{
public:
    resultat() =default;
    resultat(resultat const &r) =default;
    resultat & operator =(resultat const &r) =default;

    void ajouternumero(int const &numero);
    void trier();

    std::ostream & sortieflux(std::ostream &s) const;

private:
    liste_entiers _liste;
};

std::ostream & operator << (std::ostream &s, resultat const &r);
