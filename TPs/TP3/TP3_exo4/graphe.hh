#pragma once

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

struct arc_sortant{
    std::string _etiquette;
    unsigned int _extremite;
};

using arcs_list = std::list<arc_sortant>;

class sommet{
public:

    sommet(std::string etiquette);

    unsigned int id() const { return _identifiant; }
    std::string etiquette() const { return _etiquette; }

    void ajouterarc (unsigned int id_extremite, std::string etiquette_extremite);
    void supprimerarc (unsigned int id_extremite);
    void supprimertousarcs();
    void dot_etiquette(std::ostream &s) const ;
    void dot_arcssortants(std::ostream &s) const;

private:
    unsigned int _identifiant;
    std::string _etiquette;
    arcs_list _arcs;

    static unsigned int __cpt;
};

using sommets_list = std::list<sommet>;

class graphe {

public:
    graphe() = default;

    unsigned int ajoutersommet(std::string const &etiquette);
    bool ajouterarc(unsigned int const &id1, unsigned int const &id2, std::string const &etiquette);
private:
    sommets_list _sommets;

    sommets_list::iterator recherche (unsigned int const &id);
};
