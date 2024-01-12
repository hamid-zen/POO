#pragma once

#include <map>
#include "date.hh"
#include "resultat.hh"

using map_resultat = std::map<date, resultat>;
using ensemble_dates = std::vector<date>;

class ensembleresultat
{
public:
    ensembleresultat() =default;

    void ajout (date const &d, resultat const &r);
    resultat resultatdu(date const &d) const;
    ensemble_dates dates() const;
private:
    map_resultat _ensemble;
};

