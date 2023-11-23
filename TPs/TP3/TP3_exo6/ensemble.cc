#include "ensemble.hh"

// Ensemble
ensemble::ensemble(ensemble &e)
{
    // Comment initialiser un truc du meme type que this ??
    // Appeler le constructeur de la classe de this ??

    // On parcourt l'ensemble donné
    parcours p = e.new_parcours();
    while (!e.estfini(p)){
        // On l'ajoute quelques part
        p=e.suivant(p);
    }
}

void ensemble::ajouter(const int &x)
{
    if (!appartient(x))
        ajouter_sans_verif(x);
}

void ensemble::enlever(const int &x)
{
    if (appartient(x))
        enlever_sans_verif(x);
}

void ensemble::union_ensembles(ensemble &e)
{
    // Le resultat sera stocké dans this
    // On parcourt ainsi e et on ajoute a chaque fois que l'element n'est pas dans this
    parcours p = e.new_parcours();
    while (!e.estfini(p)){
        ajouter(e.courant(p));
        e.suivant(p);
    }

}

void ensemble::intersection_ensembles(ensemble &e)
{
    // Le resultat sera stocké dans this
    // On parcourt ainsi this et on enleve a chaque fois que l'element n'est pas dans e
    parcours p = new_parcours();
    while (!estfini(p)){

        if (!e.appartient(courant(p)))
            enlever(courant(p));
        // Vu que enlever me fait techniquement avance donc je met un else
        else
            p=suivant(p);
    }
}

void ensemble::difference_ensembles(ensemble &e)
{
    // A peut pres la meme chose que l'intersection
    // Mais ici on retire a chaque fois que l'element est aussi dans e
    parcours p = new_parcours();
    while (!estfini(p)){

        if (e.appartient(courant(p)))
            enlever(courant(p));
        // Vu que enlever me fait techniquement avance donc je met un else
        else
            p=suivant(p);
    }
}

// Ensemble tableau
ensembletableau::ensembletableau()
    : _tab(nullptr), _taille(0) {}

ensembletableau::ensembletableau(const ensembletableau &e)
    : _tab(new int[e._taille]), _taille(e._taille)
{
    for (t_taille i=0; i<e._taille; i++)
        _tab[i] = e._tab[i];
}

ensembletableau::ensembletableau(const ensemble &e)
    : _tab(nullptr), _taille(0){
    parcours2 p = e.init_parcours();
    while (!e.estfini(p)){
        ajouter(e.courant(p));
        e.suivant(p);
    }
}

bool ensembletableau::appartient(const int &x) const
{
    for (t_taille i=0; i<_taille; i++)
        if (_tab[i] == x)
            return true;
    return false;
}

bool ensembletableau::vide() const
{
    return ((_taille == 0) && (_tab == nullptr));
}

void ensembletableau::afficher() const
{
    char sep=' ';
    std::cout << "{";
    for (t_taille i=0; i<_taille; i++){
        std::cout << sep << _tab[i];
        sep = ',';
    }
    std::cout << " }\n";
}

parcours ensembletableau::new_parcours()
{
    return _tab;
}

void ensembletableau::ajouter_sans_verif(const int &x)
{
    // On fait une copie du tableau en lui rajoutant une case
    int *copie = new int[_taille+1];
    for (t_taille i=0; i<_taille; i++){
        copie[i] = _tab[i];
    }

    // On rajoute la derniere case
    copie[_taille] = x;

    // On supprime l'ancien tab et on reaffecte la copie et la taille
    delete[] _tab;
    _tab = copie;
    _taille++;
}

void ensembletableau::enlever_sans_verif(const int &x)
{
    for (t_taille i=0; i<_taille; i++)
        if (_tab[i] == x){
            // On fait decale tout le tableau a partir d'ici
            for (t_taille j=i; j<_taille-1; j++)
                _tab[j] = _tab[j+1];

            _taille--;
            return;
        }
}

ensembletableau::~ensembletableau()
{
    delete[] _tab;
}

// Ensemble vecteur
ensemblevector::ensemblevector()
    : _vector() {}


ensemblevector::ensemblevector(const ensemble &e)
    : _vector() {
    parcours2 p = e.init_parcours();
    while (!e.estfini(p)){
        ajouter(e.courant(p));
        e.suivant(p);
    }
}
bool ensemblevector::appartient(const int &x) const
{
    return (std::find(_vector.begin(), _vector.end(), x) != _vector.end());
}

bool ensemblevector::vide() const
{
    return (_vector.empty());
}

void ensemblevector::afficher() const
{
    char sep=' ';
    std::cout << "{";
    for (auto e:_vector){
        std::cout << sep << e;
        sep = ',';
    }
    std::cout << " }\n";
}

parcours ensemblevector::new_parcours()
{
    return &(*_vector.begin());
}

void ensemblevector::ajouter_sans_verif(const int &x)
{
    _vector.push_back(x);
}

void ensemblevector::enlever_sans_verif(const int &x)
{
    _vector.erase(std::find(_vector.begin(), _vector.end(), x));
}
