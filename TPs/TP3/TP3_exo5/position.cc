#include "position.hh"

//-- Position

// Constructeur
position::position(coordonnee const &x, coordonnee const &y)
    :_x(x), _y(y){}

// Comparaison
bool position::egale(position const &p) const{
    return ((p.x() == x()) && (p.y() == y()));
}

bool position::differentes(const position &p) const
{
    return !egale(p);
}

std::string position::tostring() const {
    return "("+std::to_string(_x)+", "+std::to_string(_y)+")";
}

// Taille
taille::taille(const coordonnee &w, const coordonnee &l)
    : _w(w), _l(l) {}
