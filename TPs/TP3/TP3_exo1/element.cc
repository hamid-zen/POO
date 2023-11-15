#include "taille_position.hh"
#include "element.hh"

// element
element::element(taille t, position p)
    :_taille(t), _position(p) {}

std::string element::tostring() const
{
    return "element: "+_taille.tostring()+" , "+_position.tostring();
}

bool element::contientposition(position p) const
{
    return (p.getX() >= _position.getX()) && (p.getX() <= _position.getX()+_taille.getLargeur())
        && (p.getY() >= _position.getY()) && (p.getY() <= _position.getY()+_taille.getHauteur());
};


// objet ramassable
objetramassable::objetramassable(taille t, position p, int points)
    : element(t, p), _points(points) {}

std::string objetramassable::tostring() const
{
    return "obj: "+accesposition().tostring()+" "+accestaille().tostring() + " "+std::to_string(accespoints())+" points";
};


// personnage
personnage::personnage(taille t, position p, std::string n)
    : element(t, p), _points(0), _nom(n) {};

std::string personnage::tostring() const
{
    return "perso: "+accesposition().tostring()+" "+accestaille().tostring() + " "+std::to_string(accespoints())+" points "+accesnom();
}

void personnage::ramasser(objetramassable o)
{
    _points += o.accespoints();
};


// obstacle
obstacle::obstacle(taille t, position p)
    : element(t, p) {};

std::string obstacle::tostring() const
{
    return "obs: "+accesposition().tostring()+" "+accestaille().tostring();
};
