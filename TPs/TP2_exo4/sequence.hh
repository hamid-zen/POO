#pragma once

#include <iostream>
#include <vector>

// type couleur
enum class couleur { rouge, bleu, jaune, vert };

using indicesequence = std::vector<couleur>::size_type;
using vecteur_couleurs = std::vector<couleur>;

// Classe
class sequence
{
    public:

        // constructeurs
        sequence();
        sequence(sequence const& s) = default;

        // getter
        indicesequence taille() const {return _taille;}

        // methodes
        void ajouter(couleur c);
        couleur acces(indicesequence indice) const;
        void afficher(couleur c) const;
        void vider();
        void afficher(std::ostream &flux) const;
        bool comparer(sequence &s) const;
        void copier(sequence &s) const;

        ~sequence();

    private:
        indicesequence _taille;
        vecteur_couleurs _couleurs;
};
