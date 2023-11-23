#pragma once

#include "position.hh"
#include <iostream>

enum class direction {stop, droite, gauche};

class objet {
    private:
        position _position;
        taille _taille;

    public:
        // Constrcuteur
        objet(position const &p, taille const &t);

        // acces
        position pos() const {return _position;};
        void setpos(position const &p) {_position = p;}
        taille tai() const {return _taille;}

        bool contienposition (position const &p);

        virtual char typeobjet() const = 0;

        void sortieflux(std::ostream &s) const {s << typeobjet();}

        virtual void appliquerdeplacement() = 0;

    protected:
        void settaille(taille const &t) {_taille = t;}
};

class projectile : public objet{

    public:
        projectile(position const &p);

        char typeobjet() const override {return 'P';}

        void appliquerdeplacement() override;

};

class invader : public objet{
    private:
        unsigned int _xmax;
        unsigned int _xmin;
        direction _direction;

    public:
        invader(position const &p, int xmax, int xmin, direction const &direction);

        // Acces
        unsigned int xmin() const {return _xmin;}
        unsigned int xmax() const {return _xmax;}
        direction dir() const {return _direction;}
        void setdir(direction const &d) {_direction = d;}

        char typeobjet() const override {return 'I';}

        void appliquerdeplacement() override;
};

class joueur : public objet{

    private:
        unsigned int _xmax;
        unsigned int _xmin;
        direction _direction;

    public:
        joueur(position const &p, taille const &t, int xmax, int xmin, direction const &direction);

        // Acces
        unsigned int xmin() const {return _xmin;}
        unsigned int xmax() const {return _xmax;}
        direction dir() const {return _direction;}
        void setdir(direction const &d) {_direction = d;}

        void malus();
        void bonus();

        char typeobjet() const override {return 'J';}

        void appliquerdeplacement() override;
};
