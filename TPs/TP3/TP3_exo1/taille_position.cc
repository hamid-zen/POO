#include "taille_position.hh"

//-- Position
// Getters (toujours methodes constantes) (code peut etre mis dans le hh)
coordonnee position::getX() const {
    return x;
}

coordonnee position::getY() const {
    return y;
}

// Setters
void position::setX(coordonnee x){
    this->x = x;
}

void position::setY(coordonnee y){
    this->y = y;
}

// Constructeur
position::position(coordonnee x, coordonnee y)
    :x(x), y(y){}

// Constructeur par recopie
position::position(const position & p)
    : x(p.x), y(p.y){}

// Comparaison
bool position::compareTo(position p){
    return ((p.getX() == getX()) && (p.getY() == getY()));
}

std::string position::tostring() const {
    return "("+std::to_string(x)+", "+std::to_string(y)+")";
}

//-- Taille
coordonnee taille::getHauteur() const {
    return hauteur;
}

coordonnee taille::getLargeur() const {
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
    : largeur(l), hauteur(h){}

// Constructeur par recopie
taille::taille(taille const & t)
    : largeur(t.largeur), hauteur(t.hauteur){}

// Comparaison
bool taille::compareTo(taille t){
    return ((t.getHauteur() == getHauteur()) && (t.getLargeur() == getLargeur()));
}

std::string taille::tostring() const {
    return "["+std::to_string(largeur)+", "+std::to_string(hauteur)+"]";
}
