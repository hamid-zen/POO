#include <iostream>
#include "tailleposition.hh"

using namespace std;

int main()
{

    position p(1, 2);
    position q(p);
    p.setX(9);

    taille t(1, 3);
    taille t2(t);
    t.setHauteur(9);

    return 0;
}
