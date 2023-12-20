#include "banque.hh"

int main()
{
    auto p1 = proprietaire::fabriquerproprietaire("Hamid", "10 BD Beaussier", "18/12/2002");
    auto p2 = proprietaire::fabriquerproprietaire("Nour", "Rue de la gare", "02/06/2004");

    auto s = proprietaire::fabriquerproprietaire("SAS Ando BC",
                                                 "10 place academie",
                                                 "Hamid",
                                                 "10 BD Beaussier",
                                                 "18/12/2002");

    auto c = proprietaire::fabriquerproprietaire("Hamid",
                                                 "10 BD Beaussier",
                                                 "18/12/2002",
                                                 "Nour",
                                                 "Rue de la gare",
                                                 "02/06/2004");

    std::cout << *p1 << "\n";
    std::cout << *p2 << "\n";
    std::cout << *s << "\n";
    std::cout << *c << "\n";

    return 0;
}
