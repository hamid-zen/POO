#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using t_taille = std::size_t;
using t_vector = std::vector<int>;
using parcours = int*;

class ensemble {
    public:
        ensemble() = default;
        ensemble(ensemble &e);

        virtual bool appartient(const int &x) const = 0;
        virtual bool vide() const = 0;

        void ajouter(const int &x);
        virtual void ajouter_sans_verif(const int &x) = 0;

        virtual void afficher() const = 0;

        void enlever(const int &x);
        virtual void enlever_sans_verif(const int &x) = 0;

        parcours suivant(parcours const &p) const {return (p+1);}
        int courant(parcours const &p) const { return *p;}
        virtual parcours new_parcours() = 0;
        virtual bool estfini(parcours const &p) const = 0;

        void union_ensembles(ensemble &e);

        void intersection_ensembles(ensemble &e);

        void difference_ensembles(ensemble &e);

};

class ensembletableau : public ensemble {
    private:
        int* _tab;
        t_taille _taille;
        void ajouter_sans_verif(const int &x);
        void enlever_sans_verif(const int &x);

    public:
        // Constructeurs
        ensembletableau();
        ensembletableau(const ensembletableau &e);
        ~ensembletableau();

        bool appartient(const int &x) const override;

        bool vide() const override;

        void afficher() const override;

        parcours new_parcours() override;
        bool estfini(parcours const &p) const override { return p==(_tab+(_taille));}

};

class ensemblevector : public ensemble {
    private:
        t_vector _vector;
        void ajouter_sans_verif(const int &x);
        void enlever_sans_verif(const int &x);

    public:
        // Constructeur
        ensemblevector();
        ensemblevector(const ensemblevector &e);

        bool appartient(const int &x) const override;

        bool vide() const override;

        void afficher() const override;

        parcours new_parcours() override;
        bool estfini(parcours const &p) const override {return p==&(*_vector.end());}

};
