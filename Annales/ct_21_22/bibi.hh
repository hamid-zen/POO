#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
#include <memory>

enum class langages_t { cplusplus, javascript, php, python};
enum class typepersonne_t {M1, M2, Enseingant};

class personne {
private:
    std::string _nom;

public:
    personne(std::string const &nom);

    virtual typepersonne_t typepers() const =0;

    virtual void sortieflux(std::ostream &s) const;

    virtual bool expert() const =0;

    std::string nom() const;

    virtual std::unique_ptr<personne> clone() const =0;
};

std::ostream &operator << (std::ostream &s, personne const &p);

class etudiant : public personne {
private:
    unsigned int _numero_etudiant;
    static unsigned int __current_id;

public:
    etudiant(std::string const &nom);
};

class etudiantM1 : public etudiant {
private:
    std::vector<langages_t> _langages;
    etudiantM1(std::string const &nom, std::vector<langages_t> const &langages);

public:
    static etudiantM1 fabrique(std::string const &nom, std::vector<langages_t> const &langages);

    typepersonne_t typepers() const override { return typepersonne_t::M1; }

    bool maitriselangage(langages_t const & langage) const { return std::find(_langages.begin(), _langages.end(), langage) != _langages.end(); }

    void sortieflux(std::ostream &s) const override;

    bool expert() const override { return _langages.size()>=3;}

    std::unique_ptr<personne> clone() const override { return std::make_unique<etudiantM1>(*this); }
};

class etudiantM2 : public etudiant {
private:

    unsigned int _expertise;
    etudiantM2(std::string const &nom, unsigned int expertise);

public:
    static etudiantM2 fabrique(const std::string &nom, unsigned int expertise);

    typepersonne_t typepers() const override { return typepersonne_t::M2; }

    void sortieflux(std::ostream &s) const override;

    bool expert() const override { return _expertise>7;}

    std::unique_ptr<personne> clone() const override { return std::make_unique<etudiantM2>(*this); }

};

class enseignant : public personne {
private:
    unsigned int _numero_bureau;
public:
    enseignant(std::string const &nom, unsigned int numero_bureau);

    typepersonne_t typepers() const override { return typepersonne_t::Enseingant; }

    void sortieflux(std::ostream &s) const override;

    bool expert() const override { return true;}

    std::unique_ptr<personne> clone() const override { return std::make_unique<enseignant>(*this); }
};

class exceptionuniversite : public std::exception {
private:
    std::string _message;

public:
    exceptionuniversite(std::string const &message);

    const char* what() const noexcept { return _message.c_str(); }

};

class universite {
private:
    std::vector<std::unique_ptr<personne>> _membres;

public:
    universite() =default;

    void ajouter(personne const &p);

    std::vector<std::unique_ptr<personne>> rechercherdevs(langages_t const &langage) const;
};

class projet {
private:
    std::vector<std::unique_ptr<etudiant>> _membres;

public:
    projet() =default;

    void ajouter(personne const &p);
};
