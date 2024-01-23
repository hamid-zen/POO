#include "jeu.hh"

// Position
position::position(const coordonne &x, const coordonne &y)
    : _x(x), _y(y) {};

coordonne position::x() const
{
    return _x;
}

coordonne position::y() const
{
    return _y;
}

std::string position::tostring() const
{
    return "("+std::to_string(_x)+","+std::to_string(_y)+")";
}

bool position::operator ==(const position &p) const
{
    return (_x == p.x() && _y == p.y());
}

bool position::operator !=(const position &p) const
{
    return !(_x == p.x() && _y == p.y());
}

std::ostream &operator <<(std::ostream &s, const position &p)
{
    s << p.tostring();
    return s;
}

// Taille
taille::taille(const coordonne &w, const coordonne &l)
    : _w(w), _l(l) {};

coordonne taille::w() const
{
    return _w;
}

coordonne taille::l() const
{
    return _l;
}

std::string taille::tostring() const
{
    return "("+std::to_string(_w)+","+std::to_string(_l)+")";
}

std::ostream &operator <<(std::ostream &s, const taille &t)
{
    s << t.tostring();
    return s;
}

// Element
element::element(const position &position, const taille &taille)
    : _position(position), _taille(taille) {}

void element::sortieflux(std::ostream &s) const
{
    s << typeobjet() << pos() << "-" << tai();
}

std::ostream &operator <<(std::ostream &s, const element &e)
{
    e.sortieflux(s);
    return s;
}

bool element::contient(const element &e) const
{
    return e.pos().x() >= pos().x() && e.pos().x() <= pos().x()+tai().w()
        && e.pos().y() >= pos().y() && e.pos().y() <= pos().y()+tai().l()
        && e.pos().x()+e.tai().w() <= pos().x()+tai().w()
        && e.pos().y()+e.tai().l() <= pos().y()+tai().l();
}

bool element::intersection(const element &e) const
{
    return e.pos().x() <= pos().x() && e.pos().y() >= pos().y();
}

// element deplacable

element_deplacable::element_deplacable(const position &position, taille const &taille, direction const & direction)
    : element(position, taille), _direction(direction) {}

pacman::pacman(const position &position, direction direction)
    : element_deplacable(position, taille(13, 13), direction), _invincibilite(0) {}

void pacman::sortieflux(std::ostream &s) const
{
    element::sortieflux(s);
    s << _invincibilite;
}

// pacgomme
pacgomme::pacgomme(const position &position)
    : element(position, taille(3, 3)) {}

// Fantome
fantome::fantome(const position &position, direction direction)
    : element_deplacable(position, taille(20, 20), direction) {}

// Jeu

jeu::jeu()
    : _etat(etat_t::encours), _elements(){ srand(time(NULL));}

jeu::jeu(const jeu &j)
: _etat(j._etat), _elements()
{
    for (auto &e: j._elements){
        _elements.push_back(e->clone());
    }
}

void jeu::sortieflux(std::ostream &s) const
{
    s << "Etat: ";
    switch (_etat) {
        case etat_t::encours:
            s << "En-cours";
        break;

        case etat_t::defaite:
            s << "defaite";
        break;
        case etat_t::victoire:
            s << "victoire";
        break;
    }
    s << "\nElements: \n";
    for (auto const &e: _elements)
        s << e->typeobjet() << "\n";
}

void jeu::ajouter(const element &e)
{
    if (std::any_of(_elements.begin(), _elements.end(), [&e](std::unique_ptr<element> const &p) { return p->intersection(e);}))
        throw exceptionjeu("ajouter: Element en collision");

    _elements.push_back(e.clone());
}

void jeu::ajouterfantomes(unsigned int e)
{

    for (unsigned int i(0); i<e; i++){
        // On genere un x et un y
        auto x(rand()%(320+1)), y(rand()%(200+1)), dir_int(rand()%(5+1));

        // On genere une direction
        direction d(direction::stop);
        switch (dir_int){
            case 0:
                d = direction::bas;
                break;
            case 1:
                d = direction::droite;
                break;
            case 2:
                d = direction::gauche;
                break;
            case 3:
                d = direction::haut;
                break;
            case 4:
                d = direction::stop;
                break;
        }

        try
        {
            ajouter(fantome(position(x, y), d));
        } catch (exceptionjeu const &e){
            i--; // Pour refaire le tour
        }
    }
}

void jeu::ajouterpacgommes(unsigned int e)
{

    for (unsigned int i(0); i<e; i++){
        // On genere un x et un y
        auto x(rand()%(320+1)), y(rand()%(200+1)), dir_int(rand()%(5+1));

        try
        {
            ajouter(pacgomme(position(x, y)));
        } catch (exceptionjeu const &e){
            i--; // Pour refaire le tour
        }
    }
}

pacman &jeu::accespacman() const
{
    auto p = std::find_if(_elements.begin(), _elements.end(), [](std::unique_ptr<element> const &p) { return dynamic_cast<pacman*>(p.get()) != nullptr;});

    if (p == _elements.end())
        throw exceptionjeu("Accespacman: pacman non trouvé");

    return *dynamic_cast<pacman*>((*p).get());
}

void jeu::directionjoueur(const direction &d)
{
    auto &p(accespacman());
    p.setdir(d);
}


std::ostream& operator << (std::ostream &s, jeu const &j) {
    j.sortieflux(s);
    return s;
}

// Exception
exceptionjeu::exceptionjeu(const std::string &message)
    : _message(message) {}

const char *exceptionjeu::what() const noexcept
{
    return _message.c_str();
}


