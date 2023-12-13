#pragma once
#include <iostream>
#include <sstream> // test unaire sur les stream et <<
#include <string>
// Types
using coordonnee = signed short;

// Classes
class position
{
public:
    // Getters
    coordonnee x() const;
    coordonnee y() const;

    // Setters
    void setX(coordonnee const &x);
    void setY(coordonnee const &y);

    // Constructeur
    position(coordonnee const &x, coordonnee const &y);

    // Constructeur par recopie
    position(position const &p) = default;

    std::string tostring() const;

    // Operateurs
    bool operator==(position const &p);
    bool operator!=(position const &p);

    bool estvalide() const;

private:
    // Props
    coordonnee _x;
    coordonnee _y;
};

std::ostream &operator<<(std::ostream &s, position const &p);
