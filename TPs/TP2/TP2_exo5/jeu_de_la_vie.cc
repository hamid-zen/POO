#include "jeu_de_la_vie.hh"

grille::grille(coordonnee hauteur, coordonnee largeur)
    : _largeur(largeur), _hauteur(hauteur), _jeu(hauteur, std::vector<etatcellule>(largeur, mort)){}

void grille::afficher_grille() const
{
//    for (auto ligne : _jeu){
//        std::cout <<"|";
//        for (auto box : ligne)
//            std::cout << (box == vivant ? "*|" : " |") ;
//        std::cout <<"\n";
//    }

    for (auto ligne : _jeu){
        for (auto box : ligne)
            std::cout << (box == vivant ? "*" : " ") ;
        std::cout <<"\n";
    }

}

void grille::vider()
{
//    for (auto &ligne : _jeu)
//        std::fill(ligne.begin(), ligne.end(), mort);
    std::fill(_jeu.begin(), _jeu.end(), std::vector<etatcellule>(_largeur, mort));
}

bool grille::vivante(coordonnee hauteur, coordonnee largeur) const
{
    return ( _jeu.at(hauteur).at(largeur) == vivant );
}

void grille::generer(coordonnee hauteur, coordonnee largeur)
{
    _jeu.at(hauteur).at(largeur) = vivant;
}

void grille::tuer(coordonnee hauteur, coordonnee largeur)
{
    _jeu.at(hauteur).at(largeur) = mort;
}

void grille::ajouterstructure(structure s, coordonnee hauteur, coordonnee largeur)
{
    switch (s){
        // Doit-on verifier si le point de debut est valide ? (grille assez grande)
        case structure::oscillateurligne:
            // On suppose que la ligne fait 3 cellules
            for (int i(0); i < 3; i++)
                generer(hauteur, largeur+i);
            break;

        case structure::floraison:

            // On rajoute les lignes du dessus et celle d'en bas
            ajouterstructure(structure::oscillateurligne, hauteur, largeur+1);
            ajouterstructure(structure::oscillateurligne, hauteur+2, largeur+1);

            // On rajoute ainsi la ligne du millieu
            for (int i(0); i < 5; i+=2)
                generer(hauteur+1, largeur+i);
            break;

        case structure::planeur:

            // On commence par dessiner la ligne horizontale
            ajouterstructure(structure::oscillateurligne, hauteur, largeur);

            // On rajoute les deux points restants
            generer(hauteur+1, largeur+2);
            generer(hauteur+2, largeur+1);

            break;

        case structure::oscillateurcroix:

            // On commence par dessiner la ligne horizontale
            ajouterstructure(structure::oscillateurligne, hauteur+1, largeur);

            // On s'occupe ensuite de la ligne verticale
            for (int i(0); i < 3; i++)
                generer(hauteur+i, largeur+1);
            break;

        default:
            break;
        }
}

int grille::vivantes(coordonnee hauteur, coordonnee largeur) const
{
    int sum(0);

    // On commence soit a la ligne d'avant (si on peux) et sinon a la premiere ligne
    // Meme traitement pour la colonne
    for (coordonnee i((hauteur != 0 ? hauteur-1 : 0)); i < (hauteur != _hauteur-1 ? hauteur+2 : _hauteur); i++)
        for (coordonnee j((largeur != 0 ? largeur-1 : 0)); j < (largeur != _largeur-1 ? largeur+2 : _largeur); j++){
            if (i == hauteur && j == largeur)
                continue;
            sum += vivante(i, j);
        }

    return sum;
}

void grille::evolution(const grille &g)
{
    for (coordonnee i(0); i < _hauteur; i++)
        for (coordonnee j(0); j < _largeur; j++){
            // On verifie alors les differents cas
            int nombre_cellules_vivantes = g.vivantes(i, j);

            // cellule morte prennant vie
            if (!g.vivante(i, j) && (nombre_cellules_vivantes == 3)){
                generer(i, j);
                break;
            }

            // cellule vivante qui meurt d'isolement ou etouffement
            if (g.vivante(i, j) && (nombre_cellules_vivantes <= 1 || nombre_cellules_vivantes >= 4)){
                tuer(i, j);
                break;
            }
        }
}
