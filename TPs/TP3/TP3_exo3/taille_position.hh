#pragma once
#include <string>
// Types
using coordonnee = unsigned int;

// Classes
class position
{
    public:
        // Getters
        coordonnee getX() const;
        coordonnee getY() const;

        // Setters
        void setX(coordonnee x);
        void setY(coordonnee y);

        // Constructeur
        position(coordonnee x, coordonnee y);

        // Constructeur par recopie
        position(position const & p);

        // Comparaison
        bool compareTo(position p);

        std::string tostring() const;

    private:
        // Props
        coordonnee x;
        coordonnee y;
};

class taille
{
    public:
        // Getters
        coordonnee getLargeur() const;
        coordonnee getHauteur() const;

        // Setters
        void setLargeur(coordonnee x);
        void setHauteur(coordonnee y);

        // Constructeur
        taille(coordonnee l, coordonnee h);

        // Constructeur par recopie
        taille(taille const & p);

        // Comparaison
        bool compareTo(taille p);

        std::string tostring() const;
    private:
        // Props
        coordonnee largeur;
        coordonnee hauteur;
};
