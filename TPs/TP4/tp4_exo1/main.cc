#include "piece.hh"

int main()
{
    pion p(t_couleur::blanc, position(1, 0));
    cavalier c(t_couleur::blanc, position(0, 3));
    roi r(t_couleur::noir, position(0, 0));
    dame d(t_couleur::noir, position(3, 3));

    std::cout << p.tostring() << "\n";
    std::cout << c.tostring() << "\n";

    return 0;
}
