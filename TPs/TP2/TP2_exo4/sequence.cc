#include "sequence.hh"

// Constructeur (le default n'est pas utilisable car taille doit etre init a 0)
sequence::sequence()
    :_taille(0), _couleurs(vecteur_couleurs()){}

// Constructeur recopie par defaut

// destructeur
sequence::~sequence(){
    // Correct ????
    this->vider();
}

// methodes
void sequence::ajouter(couleur c){
    // On ajoute la couleur
    _couleurs.push_back(c);

    // On inc la taille
    _taille++;
}

couleur sequence::acces(indicesequence indice) const {
    return _couleurs.at(indice);
}

void sequence::afficher(couleur c) const {
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

void sequence::afficher(std::ostream &flux) const {

    for (auto c : _couleurs){
        switch (c) {
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

void sequence::vider() {
    _taille = 0;
    _couleurs.clear(); // vu que les elements dans le vecteur ne sont pas des pointeurs alors on n'a pas besoin de delete chaque element donc clear() suffit
}

bool sequence::comparer(sequence &s) const {
    if (this->taille() != s.taille())
        return false;
    else{
        for (indicesequence i(0); i<this->taille(); i++) {
            if (this->acces(i) != s.acces(i))
                return false;
        }
        return true;
    }
}

void sequence::copier(sequence &s) const {
    s = *this;
}
