#pragma once

#include "piece.hh"

#include <cstdlib>
#include <fstream>
#include <memory>
#include <vector>

using position_echiquier = unsigned int;

class echiquier
{
public:
    echiquier();

    echiquier(echiquier const &e);
    echiquier operator=(echiquier const &e);

    void ajouter(std::unique_ptr<piece> p);
    unsigned int valeurdujoueur(t_couleur coul) const;

    bool deplacer(position const &source, position const &destination);

    void afficher(std::ostream &stream) const;

    void sauvgarde(std::ofstream &stream) const;
    void chargement(std::ifstream &stream);

    void depart();

    static void principal();

private:
    std::vector<std::unique_ptr<piece>> _jeu;

    static position_echiquier convert_position(position const &p) { return p.x() + p.y() * 8; }
};
