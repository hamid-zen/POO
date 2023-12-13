#include "horaire.hh"
#include "message.hh"

int main()
{
    horaire h(11, 14, 15);
    horaire h2(11, 15, 8);
    horaire h3(11, 14, 16);

    std::cout << "Mois : " << h.mois() << "\n";
    std::cout << "Jour : " << h.jour() << "\n";
    std::cout << "Heure : " << h.heure() << "\n";

    std::cout << h.tostring() << "\n";

    texte t("Hamid", std::vector<std::string>(), "Hamid a envoyé un truc lorem ");
    proposition p("X", std::vector<std::string>{"Y", "Z"}, "CC C++", std::vector<horaire>{h, h2});
    reponse r("Y", std::vector<std::string>{"X"}, h, 1);
    reponse r2("Z", std::vector<std::string>{"X"}, h2, 1);
    return 0;
}
