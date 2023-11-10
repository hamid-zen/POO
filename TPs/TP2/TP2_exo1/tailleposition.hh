#pragma once

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

    private:
        // Props
        coordonnee x;
        coordonnee y;
};

class taille
{
    public:
        // Getters
        coordonnee getLargeur();
        coordonnee getHauteur();

        // Setters
        void setLargeur(coordonnee x);
        void setHauteur(coordonnee y);

        // Constructeur
        taille(coordonnee l, coordonnee h);

        // Constructeur par recopie
        taille(taille const & p);

        // Comparaison
        bool compareTo(taille p);

    private:
        // Props
        coordonnee largeur;
        coordonnee hauteur;
};
