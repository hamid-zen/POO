#include "figure.hh"

// Point
point::point()
    :_x(0), _y(0){}

point::point(int x, int y)
    :_x(x), _y(y){}

// Figure
figuregeometrique::figuregeometrique(couleur const &couleur, point const &origine)
    : _couleur(couleur), _origine(origine) {}

// Segment
segment::segment(couleur const &couleur, point const &origine, point const &extremite)
    : figuregeometrique(couleur, origine), _extremite(extremite) {}
