#include "ensembleresultat.hh"

int main()
{
    date d(2002, 12, 18);
    resultat r;
    r.ajouternumero(12);
    r.ajouternumero(1);
    r.ajouternumero(3);
    r.ajouternumero(5);
    r.ajouternumero(2);
    r.trier();

    std::cout << r << "\n";
    std::cout << d << "\n";

    ensembleresultat e;
    e.ajout(d, r);
    std::cout << e.resultatdu(d) << "\n";
    return 0;
}
