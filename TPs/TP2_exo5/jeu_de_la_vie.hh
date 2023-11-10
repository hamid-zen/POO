#pragma once

#include <iostream>
#include <vector>

// Types
using coordonnee = unsigned int;
enum class etatcellule {vivant, mort};
using t_grille = std::vector< std::vector<etatcellule> >;

class grille {
    public :
        grille() = default;
        grille(const grille &g) = default;
    private :
        t_grille jeu;
};
