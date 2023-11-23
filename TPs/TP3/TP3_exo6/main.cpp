#include "ensemble.hh"

void testensemble(ensemble &e1, ensemble &e2){

    std::cout << e1.vide() << "\n";
    std::cout << e2.vide() << "\n";

    std::cout << e1.appartient(1) << "\n";
    std::cout << e2.appartient(1) << "\n";

    for (int i = 1; i<10; i++)
        e1.ajouter(i);
    for (int i = 6; i<16; i++)
        e2.ajouter(i);

    std::cout << "Avant traitements : \n";
    e1.afficher();
    e2.afficher();

//    e1.enlever(2);
//    e2.enlever(2);
//    e1.enlever(10);
//    e2.enlever(10);
//    e1.afficher();
//    e2.afficher();

//    parcours p1 = e1.new_parcours();
//    parcours p2 = e2.new_parcours();
//    while (!e1.estfini(p1)){
//        std::cout << e1.courant(p1) << ",";
//        p1=e1.suivant(p1);
//    }
//    std::cout << "\n";
//    while (!e2.estfini(p2)){
//        std::cout << e2.courant(p2) << ",";
//        p2=e2.suivant(p2);
//    }
//    std::cout << "\n";

//    e1.union_ensembles(e2);
//    e1.afficher();
//    e2.afficher();

//    e1.intersection_ensembles(e2);
//    e1.afficher();
//    e2.afficher();

//    e1.difference_ensembles(e2);
//    e1.afficher();
//    e2.afficher();

}

int main()
{
    ensembletableau e1;
    ensemblevector e2;

    testensemble(e1, e2);
    return 0;
}
