#include "carte.hh"

// carte
bool carte::intersectionintervalles(const coordonnee &a1, const coordonnee &a2, const coordonnee &b1, const coordonnee &b2)
{
    // On suppose que a1<a2 et b1<b2
    return !((b1>=a2)||(a1>=b2));
}

bool carte::intersectionelements(const element &e1, const element &e2)
{
    // On check si on a soit une intersection dans le sens hauteur
    // soit intersection dans le sens largeur

    // dans le sens hauteur
    int e1_a1_h = e1.accesposition().getY();
    int e1_a2_h = e1_a1_h+e1.accestaille().getHauteur();
    int e2_b1_h = e2.accesposition().getY();
    int e2_b2_h = e2_b1_h+e2.accestaille().getHauteur();

    // dans le sens largeur
    int e1_a1_l = e1.accesposition().getX();
    int e1_a2_l = e1_a1_l+e1.accestaille().getLargeur();
    int e2_b1_l = e2.accesposition().getX();
    int e2_b2_l = e2_b1_l+e2.accestaille().getLargeur();

    return intersectionintervalles(e1_a1_h, e1_a2_h, e2_b1_h, e2_b2_h) &&
            intersectionintervalles(e1_a1_l, e1_a2_l, e2_b1_l, e2_b2_l);


}

carte::carte(taille const &t)
    : _taille(t), _listepers(), _listeobj(), _listeobs() {}

// Peut on retourner l'element inséré ??
personnage* carte::ajouterpersonnages(const personnage &p)
{
    _listepers.push_back(p);
    return &(_listepers.back());
}

objetramassable* carte::ajouterobjets(const objetramassable &o)
{
    _listeobj.push_back(o);
    return &(_listeobj.back());
}

obstacle* carte::ajouterobstacles(const obstacle &o)
{
    _listeobs.push_back(o);
    return &(_listeobs.back());
}

void carte::afficherpersonnages() const
{
    std::cout << "taille : " << _taille.tostring() << "\n";

    for (personnage p : _listepers)
        std::cout << p.tostring() << " -- ";
}

void carte::afficherobjets() const
{
    std::cout << "taille : " << _taille.tostring() << "\n";

    for (objetramassable o : _listeobj)
        std::cout << o.tostring() << " -- ";
}

bool carte::deplacementpossible(personnage &p, const direction &d) const
{
    // La position que prendrai le personnage en cas de deplacement reussi
    position newposition(p.accesposition());

    switch (d){
        case direction::nord:
            // Deplacement vers le haut
            newposition.setY(newposition.getY() - 1);
            break;
        case direction::sud:
            // Deplacement vers le bas
            newposition.setY(newposition.getY() + 1);
            break;
        case direction::est:
            // Deplacement vers la gauche
            newposition.setX(newposition.getX() + 1);
            break;
        case direction::ouest:
            // Deplacement vers la droite
            newposition.setX(newposition.getX() - 1);
            break;
    }

    // On cree le personnage a la nouvelle position (pour les intersections
    personnage new_perso(p.accestaille(), newposition, "");

    // On check ainsi si la nouvelle position est bien dans la carte
    if (newposition.getX() <= _taille.getLargeur() && newposition.getY() <= _taille.getHauteur() ) {

        // On check ainsi si aucun element (perso, objets, obstacles)
        // n'est en intersection avec la nouvelle position du personnage
        // Pour les personnages il faudra aussi verifier que les personnages ne sont pas les memes (sinon intersection avec lui meme)
        // La comparaison se fait par reference (reference dans la liste et pointeur comme objet comparé)
        for (std::list<personnage>::const_iterator e = _listepers.begin(); e != _listepers.end(); e++)
                if (intersectionelements(new_perso, *e) && &(*e) != &p)
                return false;
        for (auto e : _listeobj)
            if (intersectionelements(new_perso, e))
                return false;
        for (auto e : _listeobs)
            if (intersectionelements(new_perso, e))
                return false;
        return true;
    }
    // Si la position n'est pas dans la carte
    return false;
}

void carte::deplacement(personnage &p, const direction &d)
{
    // On supose ici que le p en argument represente la reference au p dans la liste
    position newposition(p.accesposition());

    // On check si le deplacement est possible
    if (deplacementpossible(p, d)){

        // On calcule la nouvelle position
        switch (d){
            case direction::nord:
                // Deplacement vers le haut
                newposition.setY(newposition.getY() - 1);
                break;
            case direction::sud:
                // Deplacement vers le bas
                newposition.setY(newposition.getY() + 1);
                break;
            case direction::est:
                // Deplacement vers la gauche
                newposition.setX(newposition.getX() + 1);
                break;
            case direction::ouest:
                // Deplacement vers la droite
                newposition.setX(newposition.getX() - 1);
                break;
        }

        // On la donne au personnage
        p.setposition(newposition);
    }
}

bool carte::ramassagepossible(const personnage &p, const objetramassable &o) const
{

    // Ils se touchent en haut si (o.x est dans l'intervalle horizontal du perso) et (o.y+o.hauteur = p.y)
    bool haut = ((o.accesposition().getX() >= p.accesposition().getX()) &&
                (o.accesposition().getX() <= p.accesposition().getX() + p.accestaille().getLargeur()) &&
                 (o.accesposition().getY()+o.accestaille().getHauteur() == p.accesposition().getY()));

    // Ils se touchent en bas si (o.x est dans l'intervalle horizontal du perso) et (o.y = p.y+p.hauteur)
    bool bas = ((o.accesposition().getX() >= p.accesposition().getX()) &&
                (o.accesposition().getX() <= p.accesposition().getX() + p.accestaille().getLargeur()) &&
                (o.accesposition().getY() == p.accesposition().getY()+p.accestaille().getHauteur()));

    // Ils se touchent a droite si (o.y est dans l'intervalle vertical du perso) et (o.x = p.x+p.largeur)
    bool droite = ((o.accesposition().getY() >= p.accesposition().getY() || o.accesposition().getX()+o.accestaille().getLargeur() >= p.accesposition().getX()) &&
                   (o.accesposition().getY() <= p.accesposition().getY() + p.accestaille().getHauteur()) &&
                   (o.accesposition().getX() == p.accesposition().getX()+p.accestaille().getLargeur()));

    // Ils se touchent a gauche si (o.y est dans l'intervalle vertical du perso) et (o.x+o.largeur = p.x)
    bool gauche = ((o.accesposition().getY() >= p.accesposition().getY() || o.accesposition().getY()+o.accestaille().getHauteur()) &&
                   (o.accesposition().getY() <= p.accesposition().getY() + p.accestaille().getHauteur()) &&
                   (o.accesposition().getX()+o.accestaille().getLargeur() == p.accesposition().getX()));

    return haut||bas||droite||gauche;
}

void carte::ramassertout(personnage &p)
{
    // On commence par detecter tout les objets ramassable a sa portée
    for (std::list<objetramassable>::iterator e = _listeobj.begin(); e != _listeobj.end();){
        if (ramassagepossible(p, *e)){
            // On ramasse l'objet
            p.ramasser(*e);

            // On supprime l'objet
            // erase me retourne directement un iterateur sur le prochain objet
            std::cout << (*e).tostring() << "ramassable \n";
            e = _listeobj.erase(e);
        }
        else{
            std::cout << (*e).tostring() << "non ramassable \n";
            e++;
        }
    }
}
