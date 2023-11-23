#include "graphe.hh"

unsigned int sommet::__cpt(0);

sommet::sommet(std::string etiquette)
    : _identifiant(__cpt++), _etiquette(etiquette), _arcs() {}

void sommet::ajouterarc(unsigned int id_extremite, std::string etiquette_extremite)
{
    // On recherche un possible arc
    arcs_list::iterator it = _arcs.begin();
    while ((it != _arcs.end()) && (it->_etiquette != etiquette_extremite))
        it++;

    if (it == _arcs.end())
        // Arc non trouvé donc on l'ajoute
        _arcs.push_back(arc_sortant {etiquette_extremite, id_extremite});
    else
        // Arc trouvé donc on le MAJ
        it->_etiquette = etiquette_extremite;
}

void sommet::supprimerarc(unsigned int id_extremite)
{
    // On recherche un possible arc
    arcs_list::iterator it = _arcs.begin();
    while ((it != _arcs.end()) && (it->_extremite != id_extremite))
        it++;
    if (it != _arcs.end())
        // Arc non trouvé donc on ne fait rien
        _arcs.erase(it);
}

void sommet::supprimertousarcs()
{
    _arcs.clear();
}

void sommet::dot_etiquette(std::ostream &s) const
{
    s << "c"+std::to_string(_identifiant)+" [label=\""+_etiquette+"\"]";
}

void sommet::dot_arcssortants(std::ostream &s) const
{
    // On parcourt nos arcs
    for (auto e: _arcs){
        // On print a chaque fois
        if (e._etiquette == "")
            s << "c" << std::to_string(_identifiant) << " -> c" << std::to_string(e._extremite) << " ; ";
        else
            s << "c" << std::to_string(_identifiant) << " -> c"+std::to_string(e._extremite)+" [label=\""+e._etiquette+"\"] ; ";
    }
}

unsigned int graphe::ajoutersommet(const std::string &etiquette)
{

    // On commence par creer un objet a ajouter
    sommet s(etiquette);

    // On l'ajoute a la liste
    _sommets.push_back(s);

    // On retourne son id
    return s.id();

}

bool graphe::ajouterarc(const unsigned int &id1, const unsigned int &id2, const std::string &etiquette)
{
    // On commence par recherche nos sommets
    sommets_list::iterator sommet_origine = recherche(id1);
    sommets_list::iterator sommet_extermite = recherche(id2);

    // Si l'un des deux n'existe pas
    if (sommet_origine==_sommets.end() || sommet_extermite==_sommets.end())
        return false;

    // Sinon on rajoute l'arc
    sommet_origine->ajouterarc(id2, etiquette);
    return true;
}

sommets_list::iterator graphe::recherche(const unsigned int &id)
{
    // On commence par recherche notre sommet de base
    sommets_list::iterator it = _sommets.begin();
    while (it != _sommets.end()){
        if (it->id() == id)
            return it;
        it++;
    }
    return it;
}
