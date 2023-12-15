#include "piece.hh"

// piece
piece::piece(const t_couleur &couleur, const position &position)
    : _couleur(couleur)
    , _position(position)
{}

std::string piece::tostring() const
{
    return std::string(1, symbole()) + ((coul() == t_couleur::noir) ? "N" : "B")
            + std::to_string(pos().x()) + "," + std::to_string(pos().y());
}

bool piece::accepterposition(const position &p) const
{
    // On recupere toutes les positions possibles
    position_vector v(deplacementspossibles());

    // On voit si la position est dedans
    return (std::find(v.begin(), v.end(), p) != v.end());
}

bool piece::deplacer(const position &destination)
{
    // On check si la positon est atteignable
    if (accepterposition(destination)){
        // On se deplace
        _position = destination;

        return true;
    }

    return false;
}

// Pion

int pion::__valeur(1);
char pion::__symbole('P');

pion::pion(const t_couleur &couleur, const position &position)
    : piece(couleur, position)
{}

position_vector pion::deplacementspossibles() const
{
    position_vector v;
    position newpos(pos());

    // Si pion blanc alors une case vers le haut
    if (coul() == t_couleur::blanc)
        newpos.setY(newpos.y() - 1);
    // Sinon une case vers le bas
    else
        newpos.setY(newpos.y() + 1);

    // On check si la position est valide
    if (newpos.estvalide())
        v.push_back(newpos);

    return v;
}

// Cavalier

int cavalier::__valeur(3);
char cavalier::__symbole('C');

cavalier::cavalier(const t_couleur &couleur, const position &position)
    : piece(couleur, position)
{}

position_vector cavalier::deplacementspossibles() const
{
    position_vector v;
    position newpos(0, 0);

    // On check les 8 positions
    // On commence par x-1 et x-2
    int x_possibilities[] = {1, 2, -1, -2};
    int autre = -2;

    for (auto actuel : x_possibilities) {
        newpos.setX(pos().x() - actuel);
        newpos.setY(pos().y() - autre);
        // On check si la position est valide
        if (newpos.estvalide())
            v.push_back(newpos);

        newpos.setY(pos().y() + autre);
        // On check si la position est valide
        if (newpos.estvalide())
            v.push_back(newpos);

        autre = actuel;
    }

    return v;
}

// Dame

int dame::__valeur(9);
char dame::__symbole('D');

dame::dame(const t_couleur &couleur, const position &position)
    : piece(couleur, position)
{}

position_vector dame::deplacementspossibles() const
{
    position_vector v;
    position newpos(0, 0);

    // On ajoute la colonne
    newpos.setX(pos().x());
    for (auto y(0); y < 8; y++) {
        newpos.setY(y);

        // On check si valide et different de la position de la dame
        if (newpos.estvalide() && newpos.y() != pos().y())
            v.push_back(newpos);
    }

    // On ajoute la ligne
    newpos.setY(pos().y());
    for (auto x(0); x < 8; x++) {
        newpos.setX(x);

        // On check si valide
        if (newpos.estvalide() && newpos.x() != pos().x())
            v.push_back(newpos);
    }

    // On ajoute la diagonale 1
    for (auto i(1); i < 8; i++) {
        newpos.setX(pos().x() - i);
        newpos.setY(pos().y() - i);

        // On check si valide
        if (newpos.estvalide())
            v.push_back(newpos);

        newpos.setX(pos().x() + i);
        newpos.setY(pos().y() + i);

        // On check si valide
        if (newpos.estvalide())
            v.push_back(newpos);
    }

    // On ajoute la diagonale 2
    for (auto i(1); i < 8; i++) {
        newpos.setX(pos().x() - i);
        newpos.setY(pos().y() + i);

        // On check si valide
        if (newpos.estvalide())
            v.push_back(newpos);

        newpos.setX(pos().x() + i);
        newpos.setY(pos().y() - i);

        // On check si valide
        if (newpos.estvalide())
            v.push_back(newpos);
    }

    return v;
}

// Roi

int roi::__valeur(20);
char roi::__symbole('R');

roi::roi(const t_couleur &couleur, const position &position)
    : piece(couleur, position)
{}

position_vector roi::deplacementspossibles() const
{
    position_vector v;
    position newpos(0, 0);

    for (auto x(pos().x() - 1); x <= pos().x() + 1; x++)
        for (auto y(pos().y() - 1); y <= pos().y() + 1; y++) {
            // On ignore la case de la piece
            if (x != pos().x() || y != pos().y()) {
                newpos.setX(x);
                newpos.setY(y);

                // On check si la position est valide
                if (newpos.estvalide())
                    v.push_back(newpos);
            }
        }

    return v;
}
