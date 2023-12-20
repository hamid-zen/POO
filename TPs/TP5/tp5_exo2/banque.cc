#include "banque.hh"

// Proprietaire

std::string proprietaire::etiquetteexpedition() const { return adresse()+"--"+nom();}

std::shared_ptr<proprietaire> proprietaire::fabriquerproprietaire(const std::string &nom,
                                                                  const std::string &adresse,
                                                                  const std::string &date_naissance)
{
    personne_physique p(nom, adresse, date_naissance);
    return std::make_shared<personne_physique>(p);
}

std::shared_ptr<proprietaire> proprietaire::fabriquerproprietaire(
    const std::string &nom,
    const std::string &adresse,
    const std::string &nom_gerant,
    const std::string &adresse_gerant,
    const std::string &date_naissance_gerant)
{
    societe s(nom, adresse, nom_gerant, adresse_gerant, date_naissance_gerant);
    return std::make_shared<societe>(s);
}

std::shared_ptr<proprietaire> proprietaire::fabriquerproprietaire(
    const std::string &nom_p1,
    const std::string &adresse_p1,
    const std::string &date_naissance_p1,
    const std::string &nom_p2,
    const std::string &adresse_p2,
    const std::string &date_naissance_p2)
{
    couple c(nom_p1, adresse_p1, date_naissance_p1, nom_p2, adresse_p2, date_naissance_p2);
    return std::make_shared<couple>(c);
}

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
societe::societe(std::string const &nom,
                 std::string const &adresse,
                 std::string const &nom_gerant,
                 std::string const &adresse_gerant,
                 std::string const &date_naissance_gerant)
    : _nom(nom)
    , _adresse(adresse)
    , _gerant(fabriquerproprietaire(nom_gerant, adresse_gerant, date_naissance_gerant))
{}

std::string societe::nom() const { return _nom; }

std::string societe::adresse() const { return _adresse; }

type_proprietaire societe::type() const { return type_proprietaire::societe;}

void societe::output(std::ostream &s) const
{
    s << nom() << ", " << adresse() << ", Gérée par "; _gerant->output(s);
}

// Couple

couple::couple(const std::string &nom_p1,
               const std::string &adresse_p1,
               const std::string &date_naissance_p1,
               const std::string &nom_p2,
               const std::string &adresse_p2,
               const std::string &date_naissance_p2)
    : _personne_1(fabriquerproprietaire(nom_p1, adresse_p1, date_naissance_p1))
    , _personne_2(fabriquerproprietaire(nom_p2, adresse_p2, date_naissance_p2))
{}

std::string couple::nom() const
{
    return _personne_1->nom() + "-" + _personne_2->nom();
}

std::string couple::adresse() const { return ((_personne_1->adresse() == _personne_2->adresse()) ? _personne_1->adresse() : _personne_1->adresse()+"-"+_personne_2->adresse()); }

type_proprietaire couple::type() const { return type_proprietaire::couple;}

void couple::output(std::ostream &s) const
{
    s << nom() << ", " << adresse() << ", p1 : "; _personne_1->output(s); s << ", p2 : "; _personne_2->output(s);
}
