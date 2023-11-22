#include "figure.hh"

// Point
point::point()
    :_x(0), _y(0){}

point::point(int x, int y)
    :_x(x), _y(y){}

// Figure
figuregeometrique::figuregeometrique(couleur const &couleur, point const &origine)
    : _couleur(couleur), _origine(origine) {}

void figuregeometrique::translation(const point &p)
{
    _origine.modifierx(_origine.accesx() + p.accesx());
    _origine.modifiery(_origine.accesy() + p.accesy());
}

// Segment
segment::segment(couleur const &couleur, point const &origine, point const &extremite)
    : figuregeometrique(couleur, origine), _extremite(extremite) {}

void segment::translation(const point &p)
{
    figuregeometrique::translation(p);

    _extremite.modifierx(_extremite.accesx() + p.accesx());
    _extremite.modifiery(_extremite.accesy() + p.accesy());
}

// Triangle
triangle::triangle(const couleur &couleur, const point &origine, const point &p2, const point &p3)
    : figuregeometrique(couleur, origine), _p2(p2), _p3(p3) {}

void triangle::translation(const point &p)
{
    figuregeometrique::translation(p);

    _p2.modifierx(_p2.accesx() + p.accesx());
    _p2.modifiery(_p2.accesy() + p.accesy());

    _p3.modifierx(_p3.accesx() + p.accesx());
    _p3.modifiery(_p3.accesy() + p.accesy());
}

// Rectangle
rectangle::rectangle(const couleur &couleur, const point &origine, const point &p2)
    : figuregeometrique(couleur, origine), _p2(p2) {}

void rectangle::translation(const point &p)
{
    figuregeometrique::translation(p);

    _p2.modifierx(_p2.accesx() + p.accesx());
    _p2.modifiery(_p2.accesy() + p.accesy());

}

bool rectangle::estcarre1() const
{
    // Origine
    int x1(accesorigine().accesx());
    int y1(accesorigine().accesy());

    // p2
    int x2(accesp2().accesx());
    int y2(accesp2().accesy());

    return ((x1+x2) == (y1+y2));
}
