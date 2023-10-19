#pragma once
#include <array>

// Types

// type couleur
enum class couleur { rouge, bleu, jaune, vert };

const int TMax(100);
using indicesequence = std::size_t;

// type sequence
struct sequence
{
    std::array<couleur, TMax> tCouleur;
    indicesequence taille;
};


// Fonctions

void sc_initialiservide(sequence &s);
void sc_ajouter(sequence &s, couleur c);
void sc_copier(sequence &copie, sequence const &originale);
couleur sc_acces(sequence const &s, indicesequence indice);
void sc_afficher(couleur c);
void sc_vider(sequence &s);
void sc_afficher(sequence const &s);
bool sc_comparer(sequence const &a, sequence const &b);

