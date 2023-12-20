#include "banque.hh"

// Proprietaire

std::string proprietaire::etiquetteexpedition() const { return adresse()+"--"+nom();}

std::ostream& operator<<(std::ostream &s, proprietaire const &p)
{
    p.output(s);
    return s;
}

// Personne physique
personne_physique::personne_physique(const std::string &nom, const std::string &adresse, const std::string &date_naissance)
    : _nom(nom), _adresse(adresse), _date_naissance(date_naissance) {}

std::string personne_physique::nom() const { return _nom; }

std::string personne_physique::adresse() const { return _adresse; }

type_proprietaire personne_physique::type() const { return type_proprietaire::personne_physique;}

void personne_physique::output(std::ostream &s) const
{
    s << nom() << ", " << adresse() << ", Né le " << _date_naissance;
}

// Societe
societe::societe(const std::string &nom, const std::string &adresse, const std::shared_ptr<personne_physique> &gerant)
    : _nom(nom), _adresse(adresse), _gerant(gerant) {}

std::string societe::nom() const { return _nom; }

std::string societe::adresse() const { return _adresse; }

type_proprietaire societe::type() const { return type_proprietaire::societe;}

void societe::output(std::ostream &s) const
{
    s << nom() << ", " << adresse() << ", Gérée par "; _gerant->output(s);
}

// Couple
couple::couple(const std::shared_ptr<personne_physique> &p1, const std::shared_ptr<personne_physique> &p2)
    :  _personne_1(p1), _personne_2(p2) {}

std::string couple::nom() const { return _personne_1->nom()+"-"+_personne_2->nom(); }

std::string couple::adresse() const { return ((_personne_1->adresse() == _personne_2->adresse()) ? _personne_1->adresse() : _personne_1->adresse()+"-"+_personne_2->adresse()); }

type_proprietaire couple::type() const { return type_proprietaire::couple;}

void couple::output(std::ostream &s) const
{
    s << nom() << ", " << adresse() << ", p1 : "; _personne_1->output(s); s << ", p2 : "; _personne_2->output(s);
}
