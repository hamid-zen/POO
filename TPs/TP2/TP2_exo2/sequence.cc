#include "sequence.hh"
#include <string>

// Constructeur "defaut"
sequence::sequence()
    :_taille(0), _couleurs(nullptr){}

// Constructeur recopie
sequence::sequence(sequence const& s)
    :_taille(s._taille), _couleurs((s.taille() == 0) ? (nullptr) : (new couleur[s._taille])){
    // On recopie element par element
    for (indicesequence i(0); i<s._taille; i++)
        _couleurs[i] = s._couleurs[i];
}

// Destructeur
sequence::~sequence(){
    // Correct ????
    this->vider();
}

indicesequence sequence::taille() const {
    return _taille;
}

void sequence::ajouter(couleur c){
    // Utilisation du constructeur par recopie ????
    // On cree une copie de la bonne taille
    couleur *copie(new couleur[this->_taille+1]);

    // On recopie les elements dans le tableau
    for (indicesequence i(0); i<this->_taille; i++)
        copie[i] = _couleurs[i];

    // On rajoute la couleur
    copie[this->_taille++] = c;

    // On supprime l'ancien tableau
    delete[] _couleurs;

    // On remet le bon tableau
    _couleurs = copie;
}

couleur sequence::acces(indicesequence indice) const{
    if(indice > this->_taille)
        return couleur::bleu; // exception
    else
        return _couleurs[indice];
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
    _taille = 0;
    delete[] _couleurs;
    _couleurs = nullptr;
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

bool sequence::comparer(const sequence &s) const{
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
    s = *this;
    if(this->_couleurs != nullptr)
        delete []this->_couleurs;
}
