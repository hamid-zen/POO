#pragma once

#include <iostream>

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
};

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
};

class segment : public figuregeometrique {
    private:
        point _extremite;

    public:
        segment(couleur const &couleur, point const &origine, point const &extremite);
        segment(const segment &s) :figuregeometrique(s), _extremite(s._extremite) {std::cout << "segment: Constructeur par recopie \n";}
        ~segment() {std::cout << "segment: Destructeur \n";}

        point const & accesextremite() const {return _extremite;}
};

// TODO: Modifier triangle et rectangle (comment stocker le reste des points)
// Array ? C-Array ? Vector ?
class triangle : public figuregeometrique {
    private:
        point _points[];

    public:
        triangle(couleur const &couleur, point const &origine, point const &extremite);
        triangle(const triangle &s) :figuregeometrique(s), _points(s._points) {std::cout << "triangle: Constructeur par recopie \n";}
        ~triangle() {std::cout << "triangle: Destructeur \n";}

        point const & accespoints() const {return _points;}
};

class rectangle : public figuregeometrique {
    private:
        point _points[];

    public:
        rectangle(couleur const &couleur, point const &origine, point const &extremite);
        rectangle(const rectangle &s) :figuregeometrique(s), _points(s._points) {std::cout << "rectangle: Constructeur par recopie \n";}
        ~rectangle() {std::cout << "rectangle: Destructeur \n";}

        point const & accespoints() const {return _points;}
};
