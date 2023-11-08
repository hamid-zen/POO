#include "sequence.hh"
#include <string>
// Constructeur "defaut"
sequence::sequence()
    :_taille(0), couleurs(nullptr){}

// Constructeur recopie
sequence::sequence(sequence const& s)
    :_taille(s._taille), couleurs(new couleur[s._taille]){
    // On recopie element par element
    for (indicesequence i(0); i<s._taille; i++)
        this->couleurs[i] = s.couleurs[i];
}

// Destructeur
sequence::~sequence(){
    // Correct ????
    this->vider();
}

indicesequence sequence::taille(){
    return this->_taille;
}

void sequence::ajouter(couleur c){
    // Utilisation du constructeur par recopie ????
    // On cree une copie de la bonne taille
    couleur *copie(new couleur[this->_taille+1]);

    // On recopie les elements dans le tableau
    for (indicesequence i(0); i<this->_taille; i++)
        copie[i] = this->couleurs[i];

    // On rajoute la couleur
    copie[this->_taille++] = c;

    // On supprime l'ancien tableau
    delete[] this->couleurs;

    // On remet le bon tableau
    this->couleurs = copie;
}

couleur sequence::acces(indicesequence indice){
    if(indice > this->_taille)
        return couleur::bleu; // exception
    else
        return this->couleurs[indice];
}

void sequence::afficher(couleur c){
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

void sequence::vider(){
    // declarer un destructeur avant et y faire appel (ou le contraire?)????
    this->_taille = 0;
    delete[] this->couleurs;
    this->couleurs = nullptr;
}

void sequence::afficher(std::ostream &flux){

    for (indicesequence i(0); i<this->_taille; i++){
        switch (this->acces(i)) {
        case couleur::bleu:
            flux<<"bleu ";
            break;
        case couleur::jaune:
            flux<<"jaune ";
            break;
        case couleur::rouge:
            flux<<"rouge ";
            break;
        case couleur::vert:
            flux<<"vert ";
            break;
        default:
            break;
        }
    }
}

bool sequence::comparer(sequence &s){
    if (this->taille() != s.taille())
        return false;
    else{
        for (indicesequence i(0); i<this->taille(); i++){
            if (this->acces(i) != s.acces(i))
                return false;
        }
        return true;
    }
}

void sequence::copier(sequence &s){

    // On commence par vider l'objet
    this->vider();

    // On realloue
    this->couleurs = new couleur[s.taille()];

    // On recopie ensuite
    for (indicesequence i(0); i<s.taille(); i++)
        this->couleurs[i] = s.couleurs[i];

    // On MAJ la taille
    this->_taille = s.taille();
}
