#include "banque.hh"

int main()
{
    personne_physique p1("Hamid", "10 BD Beaussier", "18/12/2002");
    personne_physique p2("Nour", "Rue de la gare", "02/06/2004");

    societe s("SAS Ando BC", "10 place academie", std::make_shared<personne_physique>(p1));

    couple c(std::make_shared<personne_physique>(p1), std::make_shared<personne_physique>(p2));

    std::cout << p1 << "\n";
    std::cout << p2 << "\n";
    std::cout << s << "\n";
    std::cout << c << "\n";
    return 0;
}
