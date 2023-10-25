#pragma once
#include <iostream>
// Types

// type couleur
enum class couleur { rouge, bleu, jaune, vert };

// type sequence
using indicesequence = std::size_t;
struct sequence
{
    couleur *couleurs;
    indicesequence taille;

    // On rajoute la taille allouée
    indicesequence taille_allouee;
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
