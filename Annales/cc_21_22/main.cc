#include "datereleve.hh"

int main()
{
    datereleve d(2021, 11, 3, 14);
    std::cout << d.tostring() << "\n";

    datereleve d2(2022, 11, 3, 14);
    std::cout << d.comparememejour(d2) << "\n";
    std::cout << d.compareavant(d2) << "\n";

    temp t(d, 180);
    prec p(d, t_prec::pluie, 2);
    vent v(d, t_direction::Nord);
    std::cout << t.tostring() << "\n";
    std::cout << p.tostring() << "\n";
    std::cout << v.tostring() << "\n";

    t.sortiesurflux(std::cout);
    std::cout << "\n";
    p.sortiesurflux(std::cout);
    std::cout << "\n";
    v.sortiesurflux(std::cout);
    std::cout << "\n";
    return 0;
}
