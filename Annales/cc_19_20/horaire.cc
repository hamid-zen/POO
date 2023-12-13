#include "horaire.hh"

horaire::horaire(const int &mois, const int &jour, const int &heure)
    : _mois(mois)
    , _jour(jour)
    , _heure(heure)
{}

std::string horaire::tostring() const
{
    return std::to_string(_jour) + "/" + std::to_string(_mois) + "-" + std::to_string(_heure) + "h";
}
