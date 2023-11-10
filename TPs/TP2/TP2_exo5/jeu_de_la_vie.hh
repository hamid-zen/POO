#pragma once

#include <iostream>
#include <vector>

// Types
enum etatcellule {vivant, mort};
using t_grille = std::vector< std::vector<etatcellule> >;
using coordonnee = t_grille::size_type;

enum class structure {oscillateurligne, floraison, planeur, oscillateurcroix};

class grille {

    public :
        grille(coordonnee hauteur, coordonnee largeur) ;
        grille(const grille &g) = default ;
        ~grille() = default ;

        void afficher_grille() const ;

        void vider() ;
        bool vivante(coordonnee hauteur, coordonnee largeur) const ;
        void generer(coordonnee hauteur, coordonnee largeur) ;
        void tuer(coordonnee hauteur, coordonnee largeur) ;
        void ajouterstructure(structure s, coordonnee hauteur, coordonnee largeur) ;
        int vivantes(coordonnee hauteur, coordonnee largeur) const ;
        void evolution(const grille &g);
    private :
        t_grille _jeu;
        coordonnee _largeur, _hauteur;

};
