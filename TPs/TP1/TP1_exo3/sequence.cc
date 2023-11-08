#include "sequence.hh"

void sc_initialiservide(sequence &s){
    // On fixe la taille a 0
    s.taille = 0;

    // On declare le "tampon"
    s.taille_allouee = 5;
    s.couleurs = new couleur[5];
}

void sc_vider(sequence &s){
    if(s.taille != 0 and s.couleurs != nullptr)
        delete []s.couleurs;
    sc_initialiservide(s);
}

// acces a un indice hors limites (voir indice negatif)
void sc_ajouter(sequence &s, couleur c){

    // Si on a de la place dans la zone tampon on l'ajoute directement
    if (s.taille < s.taille_allouee)
        s.couleurs[s.taille++] = c;
    else{
        // Sinon alors traitement "classique"
        // On cree notre copie
        couleur *copie = new couleur[s.taille_allouee+5];

        // On copie la sequence
        for(indicesequence i= 0; i<s.taille; i++)
            copie[i] = s.couleurs[i];

        // On rajoute notre couleur
        copie[s.taille++] = c;

        // On libere l'ancienne zone memoire
        delete []s.couleurs;

        // On MAJ les infos dans s
        s.couleurs = copie;
        s.taille_allouee += 5;
    }
}

void sc_copier(sequence &copie, sequence const &originale){

    sc_initialiservide(copie);

    // On declare notre nouvelle zone
    copie.couleurs = new couleur[originale.taille];

    // On copie la sequence
    for(indicesequence i= 0; i<originale.taille; i++)
        copie.couleurs[i] = originale.couleurs[i];

    // On MAJ la taille
    copie.taille = originale.taille;
}

couleur sc_acces(sequence const &s, indicesequence indice){
    return s.couleurs[indice];
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
