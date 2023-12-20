#pragma once

#include <string>
#include <iostream>
#include <memory>

//TODO: destructeur virtuel
//TODO: Adapter
//TODO: Enlever adresse de proprietaire
//TODO: Adapter
//TODO: Delete Copy-constructors
//TODO: Private constructors
//TODO: methode fabriqueproprietaire

enum class type_proprietaire {personne_physique, societe, couple};

class proprietaire {
public:

    virtual std::string nom() const =0;
    virtual type_proprietaire type() const =0;
    virtual std::string adresse() const =0;
    virtual std::string etiquetteexpedition() const;

    virtual void output(std::ostream &s) const =0;
private:
};

std::ostream& operator<<(std::ostream &s, proprietaire const &p);

class personne_physique : public proprietaire {
private:
    std::string _nom;
    std::string _adresse;
    std::string _date_naissance;

public:
    personne_physique(std::string const &nom, std::string const &adresse, std::string const &date_naissance);

    std::string nom() const override;
    std::string adresse() const override;
    type_proprietaire type() const override;
    void output(std::ostream &s) const override;
};

class societe : public proprietaire {
private:
    std::string _nom;
    std::string _adresse;
    std::shared_ptr<personne_physique> _gerant;

public:
    societe(std::string const &nom, std::string const &adresse, std::shared_ptr<personne_physique> const &gerant);

    std::string nom() const override;
    std::string adresse() const override;
    type_proprietaire type() const override;
    void output(std::ostream &s) const override;
};

class couple : public proprietaire {
private:
    std::shared_ptr<personne_physique> _personne_1;
    std::shared_ptr<personne_physique> _personne_2;

public:
    // Todo: constructeur
    couple(std::shared_ptr<personne_physique> const &p1, std::shared_ptr<personne_physique> const &p2);

    std::string nom() const override;
    std::string adresse() const override;
    type_proprietaire type() const override;
    void output(std::ostream &s) const override;
};
