#pragma once
#include <string>
#include "taille_position.hh"

class element {
    private:
        taille _taille;
        position _position;

    public:
        // Constructeur
        element(taille t, position p);
        // Par recopie
        element(const element &e) = default;
//        // Destructeur
//        ~element();

        // Acces
        taille const & accestaille() const {return _taille;}
        position const & accesposition() const {return _position;}

        std::string tostring() const;

        bool contientposition(position p) const;
};

class objetramassable : public element {

    private :
        int _points;

    public :
        // Constrcuteur
        objetramassable(taille t, position p, int points);

        // acces
        int const & accespoints() const {return _points;}

        std::string tostring() const;
};

class personnage : public element {
    private :
        int _points;
        std::string _nom;

    public :
        // Constrcuteur
        personnage(taille t, position p, std::string n);

        // acces
        int const & accespoints() const {return _points;}
        std::string const & accesnom() const {return _nom;};

        std::string tostring() const;

        void ramasser(objetramassable o);
};

class obstacle : public element {

    public :
        // Constrcuteur
        obstacle(taille t, position p);

        std::string tostring() const;

};
