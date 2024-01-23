#pragma once

#include <string>
#include <iostream>
#include <memory>

class horaire
{
public:
    horaire(unsigned int heure, unsigned int jour, unsigned int mois);

    unsigned int heure() const;
    void Heure(unsigned int newHeure);
    unsigned int jour() const;
    unsigned int mois() const;

    std::string tostring() const;

    bool operator == (horaire const &h) const;
    bool operator < (horaire const &h) const;

private:
    unsigned int _heure;
    unsigned int _jour;
    unsigned int _mois;
};

std::ostream &operator << (std::ostream & s, horaire const &h);

// 2 - Type Unité et fonction
enum class unite {POO, Archi, DCRA};
std::string unite_tostring(unite const & u);

// 3 - RDV
class rdv {
public:
    rdv(horaire const &horaire_debut);
    horaire horaire_debut() const;
    virtual unsigned int duree() const =0;
    virtual bool decaler(signed int d);

    virtual void sortie_flux(std::ostream &s) const;

    virtual rdv* clone() const =0;

private:
    horaire _horaire_debut;
};

class rdv_medical : public rdv {
public:
    rdv_medical(horaire const &horaire_debut, std::string const &medecin);
    std::string medecin() const;
    unsigned int duree() const override;

    bool decaler(signed int d) override;
    void sortie_flux(std::ostream &s) const override;

    rdv* clone() const override;

private:
    std::string _medecin;
};

class crenau_ens : public rdv {
public:
    crenau_ens(horaire const &horaire_debut, unite const &matiere);
    unite matiere() const;
    unsigned int duree() const override;

    bool decaler(signed int d) override;
    void sortie_flux(std::ostream &s) const override;

    rdv* clone() const override;

private:
    unite _matiere;
};

class creneau_examen : public rdv {
public:
    creneau_examen(horaire const &horaire_debut, unsigned int duree, unite const &matiere);
    unite matiere() const;
    unsigned int duree() const override;

    bool decaler(signed int d) override;
    void sortie_flux(std::ostream &s) const override;

    rdv* clone() const override;

private:
    unite _matiere;
    unsigned int _duree;
};

class vacences : public rdv {
public:
    vacences(horaire const &horaire_debut, unsigned int duree);
    unsigned int duree() const override;

    bool decaler(signed int d) override;
    void sortie_flux(std::ostream &s) const override;

    rdv* clone() const override;

private:
    unsigned int _duree;
};

// 7 - Operateur de flux
std::ostream & operator << (std::ostream &s, rdv const & r);
