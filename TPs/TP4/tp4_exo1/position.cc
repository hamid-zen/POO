#include "position.hh"

coordonnee position::x() const
{
    return _x;
}

coordonnee position::y() const
{
    return _y;
}

// Setters
void position::setX(coordonnee const &x)
{
    _x = x;
}

void position::setY(coordonnee const &y)
{
    _y = y;
}

position::position(const coordonnee &x, const coordonnee &y)
    : _x(x)
    , _y(y)
{}

bool position::operator==(const position &p)
{
    return ((_x == p.x()) && (_y == p.y()));
}

bool position::operator!=(const position &p)
{
    return !position::operator==(p);
}

std::string position::tostring() const
{
    return "(" + std::to_string(_x) + "," + std::to_string(_y) + ")";
}

bool position::estvalide() const
{
    return ((x() >= 0) && (x() < 8) && (y() >= 0) && (y() < 8));
}

std::ostream &operator<<(std::ostream &s, position const &p)
{
    s << "(" << p.x() << "," << p.y() << ")";
    return s;
}
