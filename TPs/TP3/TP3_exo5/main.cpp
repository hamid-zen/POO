#include <iostream>
#include "objets.hh"


int main()
{
    joueur j(position(1, 0), taille(1, 1), 4, 0, direction::droite);

//    j.malus();
//    j.malus();
//    j.malus();
//    j.malus();
//    j.bonus();
//    j.bonus();
//    j.bonus();
//    j.bonus();
//    j.bonus();
//    j.bonus();
//    j.bonus();

//    std::cout << j.contienposition(position(1, 1)) << "\n";
//    std::cout << j.contienposition(position(30, 40)) << "\n";
//    std::cout << j.contienposition(position(20, 3)) << "\n";
//    std::cout << j.contienposition(position(20, 4)) << "\n";

    invader i(position(1, 0), 4, 1, direction::droite);
    projectile p(position(3, 3));

//    std::cout << j.typeobjet() << "\n";
//    std::cout << i.typeobjet() << "\n";
//    std::cout << p.typeobjet() << "\n";

//    j.sortieflux(std::cout); std::cout << "\n";
//    i.sortieflux(std::cout); std::cout << "\n";
//    p.sortieflux(std::cout); std::cout << "\n";

//    p.appliquerdeplacement();
//    p.appliquerdeplacement();
//    p.appliquerdeplacement();
//    p.appliquerdeplacement();

//    p.appliquerdeplacement();
//    p.appliquerdeplacement();
//    p.appliquerdeplacement();
//    p.appliquerdeplacement();

//    j.appliquerdeplacement();
//    j.appliquerdeplacement();
//    j.appliquerdeplacement();
//    j.appliquerdeplacement();
//    j.appliquerdeplacement();

//    i.appliquerdeplacement();
//    i.appliquerdeplacement();
//    i.appliquerdeplacement();
//    i.appliquerdeplacement();
//    i.appliquerdeplacement();
//    i.appliquerdeplacement();
//    i.appliquerdeplacement();
//    i.appliquerdeplacement();
//    i.appliquerdeplacement();
//    i.appliquerdeplacement();


    return 0;
}
