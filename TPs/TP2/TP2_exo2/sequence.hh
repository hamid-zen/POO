#pragma once
#include <iostream>

// type couleur
enum class couleur { rouge, bleu, jaune, vert };

using indicesequence = std::size_t;

// Classe
class sequence
{
    public:

        sequence();
        sequence(sequence const& s);

        indicesequence taille();

        void ajouter(couleur c);
        couleur acces(indicesequence indice);
        void afficher(couleur c);
        void vider();
        void afficher(std::ostream &flux);
        bool comparer(sequence &s);
        void copier(sequence &s);

        ~sequence();

    private:
        indicesequence _taille;
        couleur *couleurs;
};
