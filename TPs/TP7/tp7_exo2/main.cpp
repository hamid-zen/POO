#include "jeu.hh"

int main()
{
    fantome f(position(1, 1), direction::bas);
    pacman p(position(1, 1), direction::bas);
    std:: cout << f.contient(p) << p.contient(f);

    jeu j;
    std::cout << j;
    j.ajouter(p);
    std::cout << j;
    // j.ajouter(p);
    j.ajouterfantomes(10);
    j.ajouterpacgommes(10);
    std::cout << j;
    std::cout << j.accespacman();
    j.directionjoueur(direction::stop);
    std::cout << j.accespacman();
    return 0;
}
