#pragma once

#include "horaire.hh"
#include "vector"

class message
{
private:
    std::string _expediteur;
    std::vector<std::string> _destinataires;
    unsigned int _id;
    static unsigned int __id;

public:
    message(std::string const &expediteur, std::vector<std::string> const &destinataires);

    std::string expediteur() const { return _expediteur; }
    std::vector<std::string> destinataires() const { return _destinataires; }
    unsigned int id() const { return _id; }

    virtual void tostring(std::ostream &stream) = 0;
};

class texte : public message
{
private:
    std::string _texte;

public:
    texte(std::string const &expediteur,
          std::vector<std::string> const &destinataires,
          std::string const &texte);

    std::string text() const { return _texte; }

    void tostring(std::ostream &stream) override;
};

class proposition : public message
{
private:
    std::string _descriptif;
    std::vector<horaire> _listehoraires;

public:
    proposition(std::string const &expediteur,
                std::vector<std::string> const &destinataires,
                std::string const &descriptif,
                std::vector<horaire> const &listehoraires);

    std::string descriptif() const { return _descriptif; }
    std::vector<horaire> const horaires() const { return _listehoraires; }

    void tostring(std::ostream &stream) override;
};

class reponse : public message
{
private:
    horaire _choix;
    unsigned int _idproposition;

public:
    reponse(std::string const &expediteur,
            std::vector<std::string> const &destinataires,
            horaire const &choix,
            unsigned int id);

    horaire choix() const { return _choix; }
    unsigned int idproposition() const { return _idproposition; }

    void tostring(std::ostream &stream) override;
};
