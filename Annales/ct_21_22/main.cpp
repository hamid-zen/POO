#include "bibi.hh"

int main()
{
    std::vector<langages_t> v;
    v.push_back(langages_t::cplusplus);
    v.push_back(langages_t::python);

    auto e1(etudiantM1::fabrique("ZENINE", v));
    auto e2(etudiantM2::fabrique("CHREIF", 4));
    auto ens(enseignant("LEGEAY", 202));

    std::cout << e1 << "\n";
    std::cout << e2 << "\n";
    std::cout << ens << "\n";

    universite u;
    return 0;
}
