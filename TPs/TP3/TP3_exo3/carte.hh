#pragma once

#include <iostream>
#include "element.hh"
#include <list>

enum class direction {nord, sud, est, ouest};

class carte {

    private:
        taille _taille;
        std::list<personnage> _listepers;
        std::list<objetramassable> _listeobj;
        std::list<obstacle> _listeobs;

        // TODO: Revoir Implementation
        static bool intersectionintervalles (coordonnee const &a1, coordonnee const &a2, coordonnee const &b1, coordonnee const &b2);
        static bool intersectionelements (element const &e1, element const &e2);

    public:
        carte(const taille &t);

        // TODO:
        // Reflechir au type de retour
        // Check si on peut modifier un end sous forme d'iterateur
        personnage* ajouterpersonnages (personnage const & p);
        objetramassable* ajouterobjets (objetramassable const & o);
        obstacle* ajouterobstacles (obstacle const & o);

        void afficherpersonnages() const;
        void afficherobjets() const;

        bool deplacementpossible(personnage &p, direction const &d) const;

        void deplacement(personnage &p, direction const &d);

        bool ramassagepossible(personnage const &p, objetramassable const &o) const;

        void ramassertout(personnage &p);
};
