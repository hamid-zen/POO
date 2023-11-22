#include "figure.hh"

int main()
{
    couleur blanc = {0, 0, 0};

    point p;
    point p2(2, 2);
    point p3(5, 4);
    point p4(6, 2);

    figuregeometrique f(blanc, p);
    f.afficher(); std::cout << "\n";

    segment s(blanc, p3, p2);
    s.afficher(); std::cout << "\n";

    triangle t(blanc, p, p2, p3);
    t.afficher(); std::cout << "\n";

    rectangle r(blanc, p, p2);
    r.afficher(); std::cout << "\n";

    // std::cout << f.memeorigine(s) << " " << t.memeorigine(r) << "\n";

//    s.afficher(); std::cout << "\n";
//    s.translation(p2);
//    s.afficher(); std::cout << "\n";

//    std::cout << r.estcarre1() << "\n";

    return 0;
}
