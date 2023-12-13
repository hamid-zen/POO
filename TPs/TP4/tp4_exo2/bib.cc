#include "bib.hh"

// Document
document::document(const std::string &aut, const std::string &tit)
    : _auteur(aut), _titre(tit) {}

void document::sortie(std::ostream &s) const
{
    s << "A: " << _auteur << ", T: " << _titre;
}

std::ostream& operator<<(std::ostream &s, document const &d){
    d.sortie(s);
    return s;
}

// Livre
livre::livre(const std::string &aut, const std::string &tit, bool emprunt, int pages)
    : document(aut, tit), _empruntable(emprunt), _pages(pages) {}

void livre::sortie(std::ostream &s) const
{
    document::sortie(s);
    s << ", E: " << std::to_string(empruntable()) << ", C: " << std::to_string(cout_perte()) << ", P: " << std::to_string(_pages);
}

// Video
bool video::_empruntable(true);
float video::__cout_perte(70.0);

video::video(const std::string &aut, const std::string &tit, t_support support)
    : document(aut, tit), _support(support) {}

void video::sortie(std::ostream &s) const
{
    std::string support;
    switch (_support) {
        case t_support::DVD:
            support = "DVD";
            break;

        case t_support::Blu_Ray:
            support = "Blu_Ray";
            break;

        case t_support::Blu_Ray3D:
            support = "Blu_Ray3D";
            break;
    }
    document::sortie(s);
    s << ", E: " << std::to_string(empruntable()) << ", C: " << std::to_string(cout_perte()) << ", S: " << support;
}

// Periodique
bool periodique::_empruntable(false);

periodique::periodique(const std::string &aut, const std::string &tit, int pages, int numero)
    : document(aut, tit), _numero(numero), _pages(pages) {}

void periodique::sortie(std::ostream &s) const
{
    document::sortie(s);
    s << ", E: " << std::to_string(empruntable()) << ", C: " << std::to_string(cout_perte()) << ", N: " << std::to_string(_numero) << ", P: " << std::to_string(_pages);
}

bibliotheque::~bibliotheque()
{
    std::for_each(_documents.begin(), _documents.end(), delete_pointer);
}

document *bibliotheque::ajouter(const document &d)
{
    _documents.push_back(d.clone());

    return _documents.back();
}
