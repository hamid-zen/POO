#include "jeu_de_la_vie.hh"
#include <string>
#include <stdlib.h>

// Pour sleep
#include <chrono>
#include <thread>

// Pour window size
#include <sys/ioctl.h>
#include <unistd.h>

int main()
{
    system("clear");

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int hauteur_terminal = w.ws_row,largeur_terminal = w.ws_col;

    grille g(hauteur_terminal-1, largeur_terminal);

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

    g.ajouterstructure(structure::floraison, hauteur_terminal / 2, largeur_terminal - 10);

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
