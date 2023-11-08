#include "tailleposition.hh"

//-- Position
// Getters
coordonnee position::getX(){
    return x;
}

coordonnee position::getY(){
    return y;
}

// Setters
void position::setX(coordonnee x){
    x = x;
}

void position::setY(coordonnee y){
    y = y;
}

// Constructeur
position::position(coordonnee x, coordonnee y)
    :x(x), y(y){}

// Constructeur par recopie
position::position(position const & p)
    : x(p.x), y(p.y){}

// Comparaison
bool position::compareTo(position p){
    return ((p.getX() == getX()) && (p.getY() == getY()));
}

//-- Taille
coordonnee taille::getHauteur(){
    return hauteur;
}

coordonnee taille::getLargeur(){
    return largeur;
}

// Setters
void taille::setHauteur(coordonnee h){
    hauteur = h;
}

void taille::setLargeur(coordonnee l){
    largeur = l;
}

// Constructeur
taille::taille(coordonnee l, coordonnee h)
    :largeur(l), hauteur(h){}

// Constructeur par recopie
taille::taille(taille const & t)
    : hauteur(t.hauteur), largeur(t.largeur){}

// Comparaison
bool taille::compareTo(taille t){
    return ((t.getHauteur() == getHauteur()) && (t.getLargeur() == getLargeur()));
}
