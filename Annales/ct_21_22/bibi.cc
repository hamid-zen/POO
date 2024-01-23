#include "bibi.hh"

unsigned int etudiant::__current_id(0);

// Personne
std::string personne::nom() const
{
    return _nom;
}

personne::personne(const std::string &nom)
    : _nom(nom) {}

void personne::sortieflux(std::ostream &s) const
{
    switch (typepers()){
        case typepersonne_t::Enseingant:
            s << "Enseingant";
            break;
        case typepersonne_t::M1:
            s << "Etudiant M1";
            break;
        case typepersonne_t::M2:
            s << "Etudiant M2";
            break;
    }
    s << _nom;

}

std::ostream &operator << (std::ostream &s, personne const &p) { p.sortieflux(s); return s;}

// Etudiant
etudiant::etudiant(const std::string &nom)
    : personne(nom), _numero_etudiant(__current_id++) {}

// Etudiant M1
etudiantM1::etudiantM1(std::string const &nom, std::vector<langages_t> const &langages)
    : etudiant(nom), _langages(langages) {}

etudiantM1 etudiantM1::fabrique(const std::string &nom, const std::vector<langages_t> &langages)
{
    if (langages.size() >= 2)
        return etudiantM1(nom,langages);
    throw std::exception();
}

void etudiantM1::sortieflux(std::ostream &s) const
{
    personne::sortieflux(s);
    s << "-Langages: ";
    for (auto e: _langages)
        switch (e){
        case langages_t::cplusplus:
            s << " C++ ";
            break;
        case langages_t::python:
            s << " Python ";
            break;
        case langages_t::javascript:
            s << " JavaScript ";
            break;
        case langages_t::php:
            s << " PHP ";
            break;
        }
}

// Etudiant M2
etudiantM2::etudiantM2(const std::string &nom, unsigned int expertise)
    : etudiant(nom), _expertise(expertise) {}

etudiantM2 etudiantM2::fabrique(const std::string &nom, unsigned int expertise)
{
    if (expertise <= 10 && expertise >= 0)
        return etudiantM2(nom,expertise);
    throw std::exception();
}

void etudiantM2::sortieflux(std::ostream &s) const
{
    personne::sortieflux(s);
    s << "-Expertise: "<<_expertise;
}

// Enseignant
enseignant::enseignant(const std::string &nom, unsigned int numero_bureau)
    : personne(nom), _numero_bureau(numero_bureau) {}

void enseignant::sortieflux(std::ostream &s) const
{
    personne::sortieflux(s);
    s << "-Bureau: " << _numero_bureau;
}

// Exception
exceptionuniversite::exceptionuniversite(const std::string &message)
    : _message(message) {}

void universite::ajouter(const personne &p)
{
    if (std::any_of(_membres.begin(), _membres.end(), [&p](std::unique_ptr<personne> const &pp){ return pp->nom() == p.nom(); }))
        throw exceptionuniversite("Nom en double: "+p.nom());
    _membres.push_back(p.clone());
}

std::vector<std::unique_ptr<personne>> universite::rechercherdevs(const langages_t &langage) const
{
    std::vector<std::unique_ptr<personne>> v;
    for (auto &e: _membres)
        if (etudiantM1* pp = dynamic_cast<etudiantM1*>(e.get()); pp != nullptr && pp->maitriselangage(langage))
            v.push_back(e->clone());
    return v;
}


void projet::ajouter(const personne &p)
{
    auto nombre_ens = std::count_if(_membres.begin(), _membres.end(), [](std::unique_ptr<personne> const &pp){enseignant* ppe = dynamic_cast<enseignant*>(pp.get()); return ppe != nullptr; });
    auto nombre_M1 = std::count_if(_membres.begin(), _membres.end(), [](std::unique_ptr<personne> const &pp){etudiantM1* ppe = dynamic_cast<etudiantM1*>(pp.get()); return ppe != nullptr; });
    auto nombre_M2 = std::count_if(_membres.begin(), _membres.end(), [](std::unique_ptr<personne> const &pp){etudiantM2* ppe = dynamic_cast<etudiantM2*>(pp.get()); return ppe != nullptr; });

    if (nombre_ens <= 2 && nombre_M1 >= nombre_M2)
        _membres.push_back(p.clone());
    throw exceptionuniversite("ajouter: erreur");
}
