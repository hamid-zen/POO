#include "ensembleresultat.hh"


void ensembleresultat::ajout(const date &d, const resultat &r)
{
    _ensemble[d] = r;
}

resultat ensembleresultat::resultatdu(const date &d) const
{
    auto search_result = _ensemble.find(d);
    if (search_result == _ensemble.end())
        throw std::invalid_argument("resultatdu: date introuvable");

    return search_result->second;
}

ensemble_dates ensembleresultat::dates() const
{
    ensemble_dates result;

    for (auto e: _ensemble)
        result.push_back(e.first);

    std::sort(result.begin(), result.end());
    return result;
}

