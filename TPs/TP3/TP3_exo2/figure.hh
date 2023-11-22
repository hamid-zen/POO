#pragma once

#include <iostream>
#include <string>

struct couleur {
    unsigned int bleu;
    unsigned int vert;
    unsigned int rouge;
};

class point {
    private :
        int _x;
        int _y;

    public:
        point();
        point(int x, int y);
        point(const point &p) :_x(p._x), _y(p._y) {std::cout << "Point: Constructeur par recopie \n";}
        ~point() {std::cout << "Point: Destructeur \n";}

        void afficher() const {std::cout << "(" << _x << ", " << _y << ") ";}
        int accesx() const {return _x;}
        int accesy() const {return _y;}

        void modifierx(int x) {_x = x;}
        void modifiery(int y) {_y = y;}
};

// TODO: typefigure() et virtual
class figuregeometrique {
    private:
        couleur _couleur;
        point _origine;

    public:

        figuregeometrique(couleur const &couleur, point const &origine);
        figuregeometrique(const figuregeometrique &f) :_couleur(f._couleur), _origine(f._origine) {std::cout << "figuregeometrique: Constructeur par recopie \n";}
        ~figuregeometrique() {std::cout << "figuregeometrique: Destructeur \n";}

        couleur const & accescouleur() const {return _couleur;}
        point const & accesorigine() const {return _origine;}

        void afficher() const {std::cout << "{" << _couleur.rouge << ", " << _couleur.vert << ", " << _couleur.bleu << "}, "; _origine.afficher();}

        bool memeorigine (figuregeometrique const & f) {return (_origine.accesx() == f._origine.accesx()) && (_origine.accesy() == f._origine.accesy());}

        void translation (point const &p);

};

class segment : public figuregeometrique {
    private:
        point _extremite;

    public:
        segment(couleur const &couleur, point const &origine, point const &extremite);
        segment(const segment &s) :figuregeometrique(s), _extremite(s._extremite) {std::cout << "segment: Constructeur par recopie \n";}
        ~segment() {std::cout << "segment: Destructeur \n";}

        point const & accesextremite() const {return _extremite;}

        void afficher() const {figuregeometrique::afficher(); _extremite.afficher();}

        void translation (point const &p);
};

class triangle : public figuregeometrique {
    private:
        point _p2;
        point _p3;

    public:
        triangle(couleur const &couleur, point const &origine, point const &p2, point const &p3);
        triangle(const triangle &t) :figuregeometrique(t), _p2(t._p2), _p3(t._p3) {std::cout << "triangle: Constructeur par recopie \n";}
        ~triangle() {std::cout << "triangle: Destructeur \n";}

        point const & accesp2() const {return _p2;}
        point const & accesp3() const {return _p3;}

        void afficher() const {figuregeometrique::afficher(); _p2.afficher(); _p3.afficher();}

        void translation (point const &p);
};

class rectangle : public figuregeometrique {
    private:
        point _p2;

    public:
        rectangle(couleur const &couleur, point const &origine, point const &p2);
        rectangle(const rectangle &r) :figuregeometrique(r), _p2(r._p2) {std::cout << "rectangle: Constructeur par recopie \n";}
        ~rectangle() {std::cout << "rectangle: Destructeur \n";}

        point const & accesp2() const {return _p2;}

        void afficher() const {figuregeometrique::afficher(); _p2.afficher();}

        void translation (point const &p);

        bool estcarre1 () const ;
};
