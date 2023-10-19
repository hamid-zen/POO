#include "sequence.hh"
#include <iostream>

void sc_initialiservide(sequence &s){
    // On init la taille a 0
    s.taille = 0;
}

void sc_ajouter(sequence &s, couleur c){

    // On ajouter la couleur a la fin et on incremente la taille
    s.tCouleur[s.taille++] = c;

}

void sc_copier(sequence &copie, sequence const &originale){
    // On copie couelur par couleur de original vers copie
    for(indicesequence i(0); i < originale.taille; i++)
        copie.tCouleur.at(i) = originale.tCouleur.at(i);

    // On modifie la taille de la copie
    copie.taille = originale.taille;
}

couleur sc_acces(sequence const &s, indicesequence indice){
    return s.tCouleur.at(indice);
}

void sc_afficher(couleur c){
    switch (c) {
    case couleur::bleu:
        std::cout<<"bleu";
        break;
    case couleur::jaune:
        std::cout<<"jaune";
        break;
    case couleur::rouge:
        std::cout<<"rouge";
        break;
    case couleur::vert:
        std::cout<<"vert";
        break;
    default:
        break;
    }
}

void sc_vider(sequence &s){
    sc_initialiservide(s);
}

void sc_afficher(sequence const &s){
    for (indicesequence i=0; i<s.taille; ++i) {
        sc_afficher(sc_acces(s,i));
        std::cout << " ";
    }
}

bool sc_comparer(sequence const &a, sequence const &b){

    // On commence par comparer les tailles
    if(a.taille != b.taille)
        return false;

    // Sinon on compare element par element
    for(indicesequence i(0); i < a.taille; i++)
        if (sc_acces(a, i) != sc_acces(b, i))
            return false;

    return true;
}
