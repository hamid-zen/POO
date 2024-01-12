#include "resultat.hh"


void resultat::ajouternumero(const int &numero)
{

    // On check si on a moins de 5 valeurs et que la valeur donnée est bien bornée
    if (_liste.size() >= 5 || (numero > 49 || numero < 1) || std::find(_liste.begin(), _liste.end(), numero) != _liste.end())
        throw std::invalid_argument("ajouternumero: Argument Invalide => "+std::to_string(numero));
    else{
        // On l'ajoute aux valeurs
        _liste.push_back(numero);
    }

}

void resultat::trier()
{
    std::sort(_liste.begin(), _liste.end());
}

std::ostream &resultat::sortieflux(std::ostream &s) const
{
    for(auto e: _liste)
        s << e << " - ";
    return s;
}

std::ostream &operator <<(std::ostream &s, const resultat &r)
{
    r.sortieflux(s);
    return s;
}
