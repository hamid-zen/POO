#include "objets.hh"

// objet
objet::objet(const position &p, const taille &t)
    : _position(p), _taille(t) {}

bool objet::contienposition(const position &p)
{
    return ( p.x() <= _taille.w() ) && ( p.y() <= _taille.l() );
}

// Projectile
projectile::projectile(const position &p)
    : objet(p, taille(1, 1)) {}

void projectile::appliquerdeplacement()
{
    // Si y>0 on le decremente (deplacement vers le haut)
    if (pos().y() > 0){
        position new_position(pos().x(), pos().y() - 1);
        setpos(new_position);
    }
}

// Invader
invader::invader(const position &p, int xmax, int xmin, const direction &direction)
    : objet(p, taille(1, 1)), _xmax(xmax), _xmin(xmin), _direction(direction) {}

void invader::appliquerdeplacement()
{
    switch (dir()) {
        // Si stop on ne fait rien
        case direction::stop:
            break;

        case direction::droite:
            // Si xmax non atteint alors on inc x
            if (pos().x()+tai().w() < xmax()){
                setpos(position(pos().x()+1, pos().y()));
            }
            // Si xmax atteint
            else {
                // On incremente y
                setpos(position(pos().x(), pos().y()+1));

                // On repart vers la gauche
                setdir(direction::gauche);
            }
            break;

        case direction::gauche:
            // Si xmin non atteint alors on dec x
            if (pos().x() > xmin()){
                setpos(position(pos().x()-1, pos().y()));
            }
            // Si xmin atteint
            else {
                // On incremente y
                setpos(position(pos().x(), pos().y()+1));

                // On repart vers la droite
                setdir(direction::droite);
            }
            break;

        default:
            break;
    }
}

// Joueur
joueur::joueur(const position &p, const taille &t, int xmax, int xmin, const direction &direction)
    : objet(p, t), _xmax(xmax), _xmin(xmin), _direction(direction) {}

void joueur::malus()
{
    // On multiplie la largeur (avec la limite a 100)
    taille new_taille(((tai().w()*2 >= 100) ? 100 : tai().w()*2), tai().l());
    settaille(new_taille);
}

void joueur::bonus()
{
    // On divise la largeur (avec la limite a 3)
    taille new_taille(((tai().w()/2 <= 3) ? 3 : tai().w()/2), tai().l());
    settaille(new_taille);
}

void joueur::appliquerdeplacement()
{
    switch (dir()) {
        // Si stop on ne fait rien
        case direction::stop:
            break;

        case direction::droite:
            // Si xmax non atteint alors on inc x
            if (pos().x()+tai().w() < xmax()){
                setpos(position(pos().x()+1, pos().y()));
            }

            break;

        case direction::gauche:
            // Si xmin non atteint alors on dec x
            if (pos().x() > xmin()){
                setpos(position(pos().x()-1, pos().y()));
            }

            break;

        default:
            break;
    }
}
