#include "message.hh"

unsigned int message::__id(0);

message::message(const std::string &expediteur, const std::vector<std::string> &destinataires)
    : _expediteur(expediteur)
    , _destinataires(destinataires)
    , _id(__id++)
{}

texte::texte(std::string const &expediteur,
             std::vector<std::string> const &destinataires,
             std::string const &texte)
    : message(expediteur, destinataires)
    , _texte(texte)
{}

void texte::tostring(std::ostream &stream)
{
    std::string s;

    s += std::to_string(id()) + " ";
    s += expediteur() + "->";

    for (auto e : destinataires())
        s += e + " ";

    s += " TEXTE " + text();

    stream << s;
}

proposition::proposition(std::string const &expediteur,
                         std::vector<std::string> const &destinataires,
                         std::string const &descriptif,
                         std::vector<horaire> const &listehoraires)
    : message(expediteur, destinataires)
    , _descriptif(descriptif)
    , _listehoraires(listehoraires)
{}

void proposition::tostring(std::ostream &stream)
{
    std::string s;

    s += std::to_string(id()) + " ";
    s += expediteur() + "->";

    for (auto e : destinataires())
        s += e + " ";

    s += " PROPOSITION " + descriptif() + " : ";
    for (auto e : _listehoraires)
        s += e.tostring() + " ";

    stream << s;
}

reponse::reponse(const std::string &expediteur,
                 const std::vector<std::string> &destinataires,
                 const horaire &choix,
                 unsigned int id)
    : message(expediteur, destinataires)
    , _choix(choix)
    , _idproposition(id)
{}

void reponse::tostring(std::ostream &stream)
{
    std::string s;

    s += std::to_string(id()) + " ";
    s += expediteur() + "->";

    for (auto e : destinataires())
        s += e + " ";

    s += " RÉPONSE À " + std::to_string(_idproposition) + " : " + _choix.tostring();

    stream << s;
}
