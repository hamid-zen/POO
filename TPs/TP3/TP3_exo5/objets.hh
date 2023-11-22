#pragma once

#include "position.hh"

enum class direction {stop, droite, gauche};

class projectile{
    private:
        position _position;
        taille _taille;
    public:
        projectile(position const &p);

        // acces

};

class invader{
    private:
        position _position;
        taille _taille;
        int _xmax;
        int _xmin;
        direction _direction;

    public:
        invader(position const &p, int xmax, int xmin, direction const &direction);
};

class joueur{
    private:
        position _position;
        taille _taille;
        int _xmax;
        int _xmin;
        direction _direction;
    public:
        joueur(position const &p, taille const &t, int xmax, int xmin, direction const &direction);
};
