#include "jeu_de_la_vie.hh"
#include <string>
#include <stdlib.h>

// Pour sleep
#include <chrono>
#include <thread>

int main()
{
    system("clear");
    int hauteur_terminal = 38,largeur_terminal = 168;
    grille g(hauteur_terminal-1, largeur_terminal/2 - 1); // largeur/2 a cause des | de l'affichage

//    g.vider();
//    g.afficher_grille();

//    std::cout << g.vivante(0, 0) << "\n";
//    std::cout << g.vivante(2, 2) << "\n";
//    std::cout << g.vivante(3, 3) << "\n";

//    g.generer(1,1);
//    std::cout << g.vivante(1, 1) << "\n";
//    g.afficher_grille();

//    g.generer(1,1);
//    g.generer(0,1);
//    g.tuer(1, 1);
//    g.afficher_grille();

//    g.ajouterstructure(structure::oscillateurligne, 1, 1);
//    g.ajouterstructure(structure::floraison, 1, 0);
//    g.ajouterstructure(structure::oscillateurcroix, 1, 1);
//    g.ajouterstructure(structure::planeur, 1, 1);
//    g.afficher_grille();

//    g.ajouterstructure(structure::oscillateurligne, 1, 1);
//    g.afficher_grille();
//    std::cout << g.vivantes(1, 2);

    g.ajouterstructure(structure::floraison, hauteur_terminal / 2, largeur_terminal / 4);
    std::string s("");
    while (true){
        system("clear");
        g.afficher_grille();
        // std::getline(std::cin, s);
        g.evolution(g);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}
