#include "graphe.hh"

int main()
{
//    sommet angers("Angers");//0
//    sommet paris("Paris");//1
//    sommet nantes("Nantes");//2

//    angers.dot_etiquette(std::cout); std::cout << "\n";
//    paris.dot_etiquette(std::cout); std::cout << "\n";
//    nantes.dot_etiquette(std::cout); std::cout << "\n";

//    angers.ajouterarc(1, "Train");
//    angers.ajouterarc(2, "Bus");
//    nantes.ajouterarc(0, "Bus");
//    paris.ajouterarc(2, "Avion");

//    angers.dot_arcssortants(std::cout); std::cout << "\n";

//    angers.supprimertousarcs();

//    angers.dot_arcssortants(std::cout); std::cout << "\n";

    graphe g;

    unsigned int id_angers = g.ajoutersommet("Angers");
    unsigned int id_paris = g.ajoutersommet("Paris");
    unsigned int id_nantes = g.ajoutersommet("Nantes");

    std::cout << g.ajouterarc(id_angers, id_paris, "Train") << "\n";
    std::cout << g.ajouterarc(id_angers, id_nantes, "Bus") << "\n";
    std::cout << g.ajouterarc(30, id_nantes, "Bus") << "\n";
    std::cout << g.ajouterarc(id_angers, 30, "Bus") << "\n";
    std::cout << g.ajouterarc(40, 30, "Bus") << "\n";
    return 0;
}

//#include "graphe.hh"
//#include <fstream>

//void sauvergraphe(graphe const & g, std::string const & nomfichier) {
//	std::ofstream f(nomfichier);
//	g.dot_sortie(f);
//}

//int main() {
//	graphe g;
//	auto paris(g.ajoutersommet("Paris"));
//	auto angers(g.ajoutersommet("Angers"));
//	auto nantes(g.ajoutersommet("Nantes"));
//	g.ajouterarc(angers, nantes, "Bus");
//	g.ajouterarc(nantes, angers, "Bus");
//	g.ajouterarc(angers, paris, "Train");
//	g.ajouterarc(paris, nantes, "Avion");
//	sauvergraphe(g, "tout.dot");
//	g.supprimersommet(angers);
//	sauvergraphe(g, "sansangers.dot");
//	return 0;
//}
