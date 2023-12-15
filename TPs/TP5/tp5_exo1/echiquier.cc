#include "echiquier.hh"

echiquier::echiquier()
    : _jeu(64)
{}

echiquier::echiquier(const echiquier &e)
    : _jeu(64)
{
    for (auto i(0); i < 64; i++) {
        auto const &p = e._jeu[i];
        _jeu[i] = (static_cast<bool>(p) ? p->clone() : std::unique_ptr<piece>());
    }
}

echiquier echiquier::operator=(const echiquier &e)
{
    return echiquier(e);
}

void echiquier::ajouter(std::unique_ptr<piece> p)
{
    // On recupere la position
    position_echiquier pos(convert_position(p->pos()));

    // On l'ajoute au vector
    _jeu[pos] = std::move(p);
}

unsigned int echiquier::valeurdujoueur(t_couleur coul) const
{
    unsigned int sum(0);

    for (auto &p : _jeu)
        if (p->coul() == coul)
            sum += p->valeur();

    return sum;
}

bool echiquier::deplacer(const position &source, const position &destination)
{
    // On recupere les pointeur sur les cases en question
    auto &p_source(_jeu.at(convert_position(source)));
    auto &p_destination(_jeu.at(convert_position(destination)));

    // On check si source presente et deplacement possible
    if (p_source != nullptr && p_source->deplacer(destination)) {
        // On check si piece de couleur differente dans destination
        if (p_destination != nullptr) {
            if (p_destination->coul() != p_source->coul()) {
                // On supprime p_destination
                p_destination.reset();
            } else
                return false; // car destination de meme couleur
        }

        // On deplace la source vers la destination
        _jeu[convert_position(destination)] = p_source->clone();

        // On supprime celui de source de _jeu
        p_source.reset();

        return true;
    }

    return false;
}

void echiquier::afficher(std::ostream &stream) const
{
    unsigned int cpt(0);

    stream << "|";
    for (auto const &p : _jeu) {
        stream << (static_cast<bool>(p)
                       ? (std::string(1, p->symbole()) + (p->coul() == t_couleur::noir ? "N" : "B"))
                       : "  ");
        stream << "|";
        cpt++;
        if (cpt % 8 == 0)
            stream << "\n|";
    }
}

void echiquier::sauvgarde(std::ofstream &stream) const
{
    for (auto const &p : _jeu) {
        std::string ligne(static_cast<bool>(p) ? p->tostring() : "");

        // On ecrit dans le fichier
        stream << ligne << "\n";
    }
}

void echiquier::chargement(std::ifstream &stream)
{
    unsigned int i(0); // Pour le placer sur l'echiquier
    std::string ligne; // Pour recuperer chaque ligne

    char symbole;             // Pour le symbole (detecter quel constructeur appeler)
    t_couleur couleur;        // pour recuperer la couleur
    position pos(0, 0);       // Pour la position de la piece
    std::unique_ptr<piece> p; // Le nouveau pointeur

    while (!stream.eof()) {
        std::getline(stream, ligne);

        // On check si on a recup un truc
        if (ligne != "") {
            // On recupere les données
            symbole = ligne[0];
            couleur = (ligne[1] == 'N' ? t_couleur::noir : t_couleur::blanc);
            pos = position(i % 8, i / 8);

            // On supprime l'ancien objet
            if (static_cast<bool>(_jeu[i]))
                _jeu[i].reset();

            // On construit un nouvel objet
            switch (symbole) {
            case 'R':
                p = std::make_unique<roi>(couleur, pos);
                break;
            case 'D':
                p = std::make_unique<dame>(couleur, pos);
                break;
            case 'C':
                p = std::make_unique<cavalier>(couleur, pos);
                break;
            case 'P':
                p = std::make_unique<pion>(couleur, pos);
                break;
            }

            // On l'ajoute a l'echiquier
            ajouter(std::move(p));
        }

        i++;
    }
}

void echiquier::depart()
{
    std::unique_ptr<piece> p; // Le nouveau pointeur

    // On remplit les lignes de pions
    for (auto i(0); i < 8; i++) {
        // Pions blancs
        p = std::make_unique<pion>(t_couleur::noir, position(i, 1));
        ajouter(std::move(p));

        // Pions noirs
        p = std::make_unique<pion>(t_couleur::blanc, position(i, 6));
        ajouter(std::move(p));
    }

    // On place les cavaliers
    p = std::make_unique<cavalier>(t_couleur::noir, position(1, 0));
    ajouter(std::move(p));
    p = std::make_unique<cavalier>(t_couleur::blanc, position(6, 0));
    ajouter(std::move(p));

    p = std::make_unique<cavalier>(t_couleur::noir, position(1, 7));
    ajouter(std::move(p));
    p = std::make_unique<cavalier>(t_couleur::blanc, position(6, 7));
    ajouter(std::move(p));

    // On place les rois
    p = std::make_unique<roi>(t_couleur::noir, position(3, 0));
    ajouter(std::move(p));

    p = std::make_unique<roi>(t_couleur::blanc, position(3, 7));
    ajouter(std::move(p));

    // On place les dames
    p = std::make_unique<dame>(t_couleur::noir, position(4, 0));
    ajouter(std::move(p));

    p = std::make_unique<dame>(t_couleur::blanc, position(4, 7));
    ajouter(std::move(p));
}

void echiquier::principal()
{
    echiquier e;
    e.depart();

    t_couleur couleur(t_couleur::blanc);      // couleur joueur actuel
    unsigned int x, y;                        // position sous forme d'entier
    position source(0, 0), destination(0, 0); // traduction du choix
    bool valide(false);                       // validité des choix

    while (1) {
        do {
            system("clear");
            std::cout << "Au tour du joueur " << ((couleur == t_couleur::blanc) ? "Blanc" : "Noir")
                      << "\n";
            e.afficher(std::cout);
            // On recupere la position initiale
            std::cout << "Entrez la position de la piece a deplacer: ";
            std::cin >> x >> y;
            source = position(x, y);

            valide = source.estvalide() || e._jeu.at(convert_position(source))->coul() != couleur;

            // On affiche un message si non valide
            if (!valide) {
                std::cout << "Position initiale invalide \n";
                continue;
            }

            // On recupere la position destination
            std::cout << "Entrez la position destination : ";
            std::cin >> x >> y;
            destination = position(x, y);

            valide = destination.estvalide();

            // On affiche un message si non valide
            if (!valide) {
                std::cout << "Position destination invalide \n";
                continue;
            }

            // On tente de faire le deplacement
            valide = e.deplacer(source, destination);

            if (valide)
                std::cout << "Deplacement reussi \n";

            // On switch la couleur
            if (couleur == t_couleur::blanc)
                couleur = t_couleur::noir;
            else
                couleur = t_couleur::blanc;

            e.afficher(std::cout);
        } while (!valide);
    }
}
