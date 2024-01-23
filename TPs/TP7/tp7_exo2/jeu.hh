#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <exception>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

// 2
using coordonne = unsigned int;

class position
{
private:
    coordonne _x;
    coordonne _y;

public:
    position(coordonne const &x, coordonne const &y);
    coordonne x() const;
    coordonne y() const;
    std::string tostring() const;

    bool operator == (position const &p) const;
    bool operator !=(const position &p) const;

};

std::ostream& operator << (std::ostream &s, position const &p);

// 3
class taille
{
private:
    coordonne _w;
    coordonne _l;

public:
    taille(coordonne const &w, coordonne const &l);
    coordonne w() const;
    coordonne l() const;
    std::string tostring() const;

};

std::ostream& operator << (std::ostream &s, taille const &t);

// 4

class element {
private:
    position _position;
    taille _taille;

public:
    element(position const &position, taille const &taille);

    taille tai() const {return _taille; }
    position pos() const { return _position; }

    void setpos(position const &p) { _position = p; }

    virtual char typeobjet() const =0;

    virtual void sortieflux(std::ostream &s) const;

    bool contient(element const &e) const;
    bool intersection(const element &e) const;

    virtual std::unique_ptr<element> clone() const =0;
};

std::ostream &operator << (std::ostream &s, element const &e);

// 1

enum class direction {stop, gauche, droite, haut, bas};

class element_deplacable : public element{
private:
    direction _direction;

public:
    element_deplacable(position const &position, taille const &taille, direction const & direction);

    direction deplacement() const {return _direction;}
    void setdir(direction const &d) {_direction = d;}
};

class pacman : public element_deplacable {
private:
    unsigned int _invincibilite;

public:
    pacman(position const &position, direction direction);

    char typeobjet() const override { return 'P';};

    bool invincible() const { return (_invincibilite > 0);};
    void decrementerinvincible() {_invincibilite--;};
    void devenirinvincible(){_invincibilite += 200;};

    void sortieflux(std::ostream &s) const override;

    std::unique_ptr<element> clone() const override { return std::make_unique<pacman>(*this);}
};

class pacgomme : public element{
private:

public:
    pacgomme(position const &position);
    std::unique_ptr<element> clone() const override { return std::make_unique<pacgomme>(*this);}
    char typeobjet() const override { return 'G';};
};

class fantome : public element_deplacable{
private:

public:
    fantome(position const &position, direction direction);

    char typeobjet() const override { return 'F';};
    std::unique_ptr<element> clone() const override { return std::make_unique<fantome>(*this);}
};

class mur : public element {
private:

public:
    mur(position const &position, taille const &taille);

    char typeobjet() const override { return 'M';};

    std::unique_ptr<element> clone() const override { return std::make_unique<mur>(*this);}
};

// Jeu

using vector_elements_t = std::vector<std::unique_ptr<element>>;

enum class etat_t {encours, defaite, victoire};
class jeu {
private:
    etat_t _etat;
    vector_elements_t _elements;

public:
    jeu();
    jeu(jeu const &j);
    void sortieflux(std::ostream &s) const;
    void ajouter(element const &e);

    void ajouterfantomes(unsigned int e);
    void ajouterpacgommes(unsigned int e);

    pacman& accespacman() const;

    void directionjoueur(direction const &d);
};

std::ostream& operator << (std::ostream &s, jeu const &j);


// Exception
class exceptionjeu: public std::exception {
private:
    std::string _message;

public:
    exceptionjeu(std::string const &message);

    const char* what() const noexcept ;
};
