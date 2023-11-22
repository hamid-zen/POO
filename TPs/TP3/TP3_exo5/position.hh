#pragma once
#include <string>
// Types
using coordonnee = unsigned int;

// Classes
class position
{
    public:
        // Getters
        coordonnee x() const { return _x;}
        coordonnee y() const { return _y;}

        // Setters
        void setx(coordonnee const &x) { _x=x; }
        void sety(coordonnee const &y) { _y=y; }

        // Constructeur
        position(coordonnee const &x, coordonnee const &y);

        // Comparaison
        bool egale(position const &p) const;
        bool differentes(position const &p) const;

        std::string tostring() const;

    private:
        // Props
        coordonnee _x;
        coordonnee _y;
};

class taille
{
    public:
        // Getters
        coordonnee w() const { return _w; }
        coordonnee l() const { return _l; }

        // Setters
        void setW(coordonnee w) { _w=w; }

        // Constructeur
        taille(coordonnee const &w, coordonnee const &l);

    private:
        // Props
        coordonnee _w;
        coordonnee _l;
};
