#include "horaire.hh"

int main()
{
    creneau_examen ex(horaire(8, 6, 12), 120, unite::POO);
    crenau_ens en(horaire(12, 5, 12), unite::POO);
    vacences v(horaire(8, 8, 12), 240);
    rdv_medical m(horaire(12, 12, 12), "Hoyek");

    std::cout << ex << "\n";
    std::cout << en << "\n";
    std::cout << v << "\n";
    std::cout << m << "\n";

    return 0;
}
