#include "bib.hh"

int main()
{
    livre l("Yasmina Khadra", "Ce que le jour doit à la nuit", true, 437);
    video v("Sergio Leone", "le bon la brute et le truand", t_support::DVD);
    periodique p("Henry Grunwald", "Time", 32, 420);

    bibliotheque b;

    document* ll = b.ajouter(l);
    return 0;
}
