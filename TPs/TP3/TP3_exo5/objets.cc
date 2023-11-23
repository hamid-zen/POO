#include "objets.hh"


// Projectile
projectile::projectile(const position &p)
    : _position(p), _taille(1, 1) {}

// Invader
invader::invader(const position &p, int xmax, int xmin, const direction &direction)
    : _position(p), _taille(11, 8), _xmax(xmax), _xmin(xmin), _direction(direction) {}

joueur::joueur(const position &p, const taille &t, int xmax, int xmin, const direction &direction)
    : _position(p), _taille(t), _xmax(xmax), _xmin(xmin), _direction(direction) {}
