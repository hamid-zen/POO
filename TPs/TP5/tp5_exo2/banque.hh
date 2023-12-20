#pragma once

#include <iostream>
#include <memory>
#include <string>

//TODO: destructeur virtuel
//TODO: Delete Copy-constructors

enum class type_proprietaire {personne_physique, societe, couple};

class proprietaire {
public:
    //    proprietaire() = delete;
    //    proprietaire(proprietaire const &p) = delete;
    virtual std::string nom() const = 0;
    virtual type_proprietaire type() const =0;
    virtual std::string adresse() const =0;
    virtual std::string etiquetteexpedition() const;

    virtual void output(std::ostream &s) const = 0;
    static std::shared_ptr<proprietaire> fabriquerproprietaire(std::string const &nom,
                                                               std::string const &adresse,
                                                               std::string const &date_naissance);
    static std::shared_ptr<proprietaire> fabriquerproprietaire(
        std::string const &nom,
        std::string const &adresse,
        std::string const &nom_gerant,
        std::string const &adresse_gerant,
        std::string const &date_naissance_gerant);
    static std::shared_ptr<proprietaire> fabriquerproprietaire(std::string const &nom_p1,
                                                               std::string const &adresse_p1,
                                                               std::string const &date_naissance_p1,
                                                               std::string const &nom_p2,
                                                               std::string const &adresse_p2,
                                                               std::string const &date_naissance_p2);
};

std::ostream& operator<<(std::ostream &s, proprietaire const &p);

class personne_physique : public proprietaire
{
    // Pour acceder au constructeur privé
    friend std::shared_ptr<proprietaire> proprietaire::fabriquerproprietaire(
        std::string const &nom, std::string const &adresse, std::string const &date_naissance);
    friend std::shared_ptr<proprietaire> proprietaire::fabriquerproprietaire(
        std::string const &nom,
        std::string const &adresse,
        std::string const &nom_gerant,
        std::string const &adresse_gerant,
        std::string const &date_naissance_gerant);
    friend std::shared_ptr<proprietaire> proprietaire::fabriquerproprietaire(
        std::string const &nom_p1,
        std::string const &adresse_p1,
        std::string const &date_naissance_p1,
        std::string const &nom_p2,
        std::string const &adresse_p2,
        std::string const &date_naissance_p2);

public:
    std::string nom() const override;
    std::string adresse() const override;
    type_proprietaire type() const override;
    void output(std::ostream &s) const override;

private:
    std::string _nom;
    std::string _adresse;
    std::string _date_naissance;
    personne_physique(std::string const &nom,
                      std::string const &adresse,
                      std::string const &date_naissance);
};

class societe : public proprietaire
{ //Pour acceder au constructeur privé
    friend std::shared_ptr<proprietaire> proprietaire::fabriquerproprietaire(
        std::string const &nom,
        std::string const &adresse,
        std::string const &nom_gerant,
        std::string const &adresse_gerant,
        std::string const &date_naissance_gerant);

public:
    std::string nom() const override;
    std::string adresse() const override;
    type_proprietaire type() const override;
    void output(std::ostream &s) const override;

private:
    std::string _nom;
    std::string _adresse;
    std::shared_ptr<proprietaire> _gerant;
    societe(std::string const &nom,
            std::string const &adresse,
            std::string const &nom_gerant,
            std::string const &adresse_gerant,
            std::string const &date_naissance_gerant);
};

class couple : public proprietaire
{
    friend std::shared_ptr<proprietaire> proprietaire::fabriquerproprietaire(
        const std::string &nom_p1,
        const std::string &adresse_p1,
        const std::string &date_naissance_p1,
        const std::string &nom_p2,
        const std::string &adresse_p2,
        const std::string &date_naissance_p2);

public:
    std::string nom() const override;
    std::string adresse() const override;
    type_proprietaire type() const override;
    void output(std::ostream &s) const override;

private:
    std::shared_ptr<proprietaire> _personne_1;
    std::shared_ptr<proprietaire> _personne_2;
    couple(std::string const &nom_p1,
           std::string const &adresse_p1,
           std::string const &date_naissance_p1,
           std::string const &nom_p2,
           std::string const &adresse_p2,
           std::string const &date_naissance_p2);
};
