#include "bib.hh"

int main()
{
    livre l("Yasmina Khadra", "Ce que le jour doit à la nuit", true, 437);
    video v("Sergio Leone", "le bon la brute et le truand", t_support::DVD);
    periodique p("Henry Grunwald", "Time", 32, 420);

    bibliotheque b;

    b.ajouter(l);
    b.ajouter(v);
    b.ajouter(p);

    //    parcours par(b.new_parcours());
    //    par.next();
    //    par.next();
    //    par.next();
    std::cout << b.videos_type(t_support::DVD) << "\n";
    std::cout << b.videos_type(t_support::Blu_Ray) << "\n";
    std::cout << b.videos_type(t_support::Blu_Ray3D) << "\n";

    bibliotheque b2(b);
    return 0;
}
