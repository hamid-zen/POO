#include "horaire.hh"

// Horaire
horaire::horaire(unsigned int heure, unsigned int jour, unsigned int mois)
    : _heure(heure), _jour(jour), _mois(mois) {}

unsigned int horaire::heure() const
{
    return _heure;
}

void horaire::Heure(unsigned int newHeure)
{
    _heure = newHeure;
}

unsigned int horaire::jour() const
{
    return _jour;
}

unsigned int horaire::mois() const
{
    return _mois;
}

std::string horaire::tostring() const
{
    return std::to_string(_jour)+"/"+std::to_string(_mois)+" - "+std::to_string(_heure)+"h";
}

bool horaire::operator ==(const horaire &h) const
{
    return (_heure == h.heure() && _jour == h.jour() && _mois == h.jour());
}

bool horaire::operator <(const horaire &h) const
{
    return (_mois < h.mois()) || (_mois == h.mois() && _jour < h.jour()) || (_mois == h.mois() && _jour == h.jour() && _heure < h.heure());
}

std::ostream &operator << (std::ostream & s, horaire const &h)
{
    s << h.tostring();
    return s;
}

std::string unite_tostring(unite const & u) {
    switch (u) {
    case unite::Archi:
        return "Archi";
    case unite::POO:
        return "POO";
    case unite::DCRA:
        return "DCRA";
    default:
        break;
    }
}

// RDV
rdv::rdv(const horaire &horaire_debut)
    : _horaire_debut(horaire_debut) {}

horaire rdv::horaire_debut() const
{
    return _horaire_debut;
}

bool rdv::decaler(signed int d)
{
    _horaire_debut.Heure(_horaire_debut.heure()+d);
    return true;
}

void rdv::sortie_flux(std::ostream &s) const
{
    s << horaire_debut() << " - " << duree() << "mn";
}


// RDV medical
rdv_medical::rdv_medical(const horaire &horaire_debut, const std::string &medecin)
    : rdv(horaire_debut), _medecin(medecin) {}

std::string rdv_medical::medecin() const
{
    return _medecin;
}

unsigned int rdv_medical::duree() const
{
    return 60;
}

bool rdv_medical::decaler(signed int d)
{
    return false;
}

void rdv_medical::sortie_flux(std::ostream &s) const
{
    s << "RDV Medical - ";
    rdv::sortie_flux(s);
    s << " - " << _medecin;
}

rdv *rdv_medical::clone() const
{
    return new rdv_medical(*this);
}

// creanau ens
crenau_ens::crenau_ens(horaire const &horaire_debut, unite const &matiere)
    : rdv(horaire_debut), _matiere(matiere) {}

unite crenau_ens::matiere() const
{
    return _matiere;
}

unsigned int crenau_ens::duree() const
{
    return 80;
}

bool crenau_ens::decaler(signed int d)
{
    if ((d == 1 || d == -1) && ((horaire_debut().heure() + d >0) && (horaire_debut().heure() + d < 24))){
        // On decale
        return rdv::decaler(d);
    }
    return false;
}

void crenau_ens::sortie_flux(std::ostream &s) const
{
    s << "Enseignement - ";
    rdv::sortie_flux(s);
    s << " - " << unite_tostring(_matiere);
}

rdv *crenau_ens::clone() const
{
    return new crenau_ens(*this);
}

// crenau examen
creneau_examen::creneau_examen(const horaire &horaire_debut, unsigned int duree, const unite &matiere)
    : rdv(horaire_debut), _matiere(matiere) {}

unite creneau_examen::matiere() const
{
    return _matiere;
}

unsigned int creneau_examen::duree() const
{
    return _duree;
}

bool creneau_examen::decaler(signed int d)
{
    if ((d == 1 || d == -1) && ((horaire_debut().heure() + d >0) && (horaire_debut().heure() + d < 24))){
        // On decale
        return rdv::decaler(d);
    }
    return false;
}

void creneau_examen::sortie_flux(std::ostream &s) const
{
    s << "Examen - ";
    rdv::sortie_flux(s);
    s << " - " << unite_tostring(_matiere);
}

rdv *creneau_examen::clone() const
{
    return new creneau_examen(*this);
}

// vacences
vacences::vacences(const horaire &horaire_debut, unsigned int duree)
    : rdv(horaire_debut), _duree(duree) {}

unsigned int vacences::duree() const
{
    return _duree;
}

bool vacences::decaler(signed int d)
{
    return rdv::decaler(d);
}

void vacences::sortie_flux(std::ostream &s) const
{
    s << "Vacences - ";
    rdv::sortie_flux(s);
}

// operateur de flux
std::ostream & operator << (std::ostream &s, rdv const & r) {
    r.sortie_flux(s);
    return s;
}

rdv *vacences::clone() const
{
    return new vacences(*this);
}
