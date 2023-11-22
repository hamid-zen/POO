#include "carte.hh"
#include <iostream>


int main()
{
    carte c(taille(30, 30));

    personnage pers(taille(2, 2), position(1, 1), "hamid");
    personnage pers2(taille(2, 2), position(3, 4), "mehdi");

    objetramassable obj(taille(1, 1), position(3, 2), 500);
    obstacle obs(taille(5, 1), position(5, 1));
    obstacle obs2(taille(1, 1), position(4, 5));

    personnage *p2 = c.ajouterpersonnages(pers2);
    personnage *p1 = c.ajouterpersonnages(pers);

    objetramassable *objet_liste =c.ajouterobjets(obj);
    obstacle *obstacle_liste = c.ajouterobstacles(obs);
    obstacle *obstacle2_liste = c.ajouterobstacles(obs2);

//    c.afficherpersonnages();std::cout << "\n";

//    std::cout << carte::intersectionelements(pers, pers2) << "\n";
//    std::cout << carte::intersectionelements(pers, obj) << "\n";
//    std::cout << carte::intersectionelements(pers, obs) << "\n";
//    std::cout << carte::intersectionelements(pers2, obs2) << "\n";

//    std::cout << c.deplacementpossible(personnage(pers.accestaille(), position(0, 0), ""), direction::nord) << "\n";
//    std::cout << c.deplacementpossible(personnage(pers.accestaille(), position(0, 0), ""), direction::ouest) << "\n";

//    std::cout << c.deplacementpossible(*p1, direction::nord) << "\n";
//    std::cout << c.deplacementpossible(*p1, direction::sud) << "\n";
//    std::cout << c.deplacementpossible(*p1, direction::est) << "\n";
//    std::cout << c.deplacementpossible(*p1, direction::ouest) << "\n";

//    c.deplacement(*p1, direction::nord);
//    c.afficherpersonnages();std::cout << "\n";
//    c.deplacement(*p1, direction::sud);
//    c.afficherpersonnages();std::cout << "\n";
//    c.deplacement(*p1, direction::est);
//    c.afficherpersonnages();std::cout << "\n";
//    c.deplacement(*p1, direction::ouest);
//    c.afficherpersonnages();std::cout << "\n";

//    std::cout << c.ramassagepossible(*p1, obj) << "\n";
//    c.deplacement(*p1, direction::nord);
//    std::cout << c.ramassagepossible(*p1, obj) << "\n";
//    c.deplacement(*p1, direction::est);
//    std::cout << c.ramassagepossible(*p1, obj) << "\n";
//    c.deplacement(*p1, direction::est);
//    std::cout << c.ramassagepossible(*p1, obj) << "\n";
//    c.deplacement(*p1, direction::est);
//    std::cout << c.ramassagepossible(*p1, obj) << "\n";
//    c.deplacement(*p1, direction::sud);
//    std::cout << c.ramassagepossible(*p1, obj) << "\n";
//    c.deplacement(*p1, direction::sud);
//    std::cout << c.ramassagepossible(*p1, obj) << "\n";
//    c.deplacement(*p1, direction::sud);
//    std::cout << c.ramassagepossible(*p1, obj) << "\n";
//    c.deplacement(*p1, direction::ouest);
//    std::cout << c.ramassagepossible(*p1, obj) << "\n";
//    c.deplacement(*p1, direction::ouest);
//    std::cout << c.ramassagepossible(*p1, obj) << "\n";
//    c.deplacement(*p1, direction::ouest);
//    std::cout << c.ramassagepossible(*p1, obj) << "\n";
//    c.deplacement(*p1, direction::ouest);
//    std::cout << c.ramassagepossible(*p1, obj) << "\n";
//    c.afficherpersonnages();std::cout << "\n";

    objetramassable obj2(taille(1, 1), position(1, 3), 500);
    objetramassable *objet2_liste =c.ajouterobjets(obj2);
    objetramassable obj3(taille(1, 1), position(7, 4), 500);
    objetramassable *objet3_liste =c.ajouterobjets(obj3);
    std::cout << "Avant ramassage : \n";
    c.afficherobjets();std::cout << "\n";
    c.afficherpersonnages();std::cout << "\n";
    c.ramassertout(*p1);
    std::cout << "Apres ramassage : \n";
    c.afficherobjets();std::cout << "\n";
    c.afficherpersonnages();std::cout << "\n";

    return 0;
}
