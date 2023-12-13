#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class document {
public:
    document(std::string const &aut, std::string const &tit);

    std::string auteur() const {return _auteur;}
    std::string titre() const {return _titre;}

    virtual bool empruntable() const =0;
    virtual float cout_perte() const =0;

    virtual void sortie(std::ostream &s) const;

    virtual document* clone() const =0;

private:
    std::string _auteur;
    std::string _titre;
};

class livre : public document {
public:
    livre(std::string const &aut, std::string const &tit, bool emprunt, int pages);

    bool empruntable() const override {return _empruntable;}
    float cout_perte() const override { return 0.5*_pages;}

    void sortie(std::ostream &s) const override;

    document* clone() const override { return new livre(*this);}

private:
    bool _empruntable;
    int _pages;
};

enum class t_support {DVD, Blu_Ray, Blu_Ray3D};

class video : public document {
public:
    video(std::string const &aut, std::string const &tit, t_support support);

    bool empruntable() const override {return _empruntable;}
    float cout_perte() const override { return __cout_perte;}

    void sortie(std::ostream &s) const override;

    document* clone() const override { return new video(*this);}

private:
    static bool _empruntable;
    static float __cout_perte;
    t_support _support;
};

class periodique : public document {
public:
    periodique(std::string const &aut, std::string const &tit, int pages, int numero);

    bool empruntable() const override {return _empruntable;}
    float cout_perte() const override { return 0.5*_pages;}

    void sortie(std::ostream &s) const override;

    document* clone() const override { return new periodique(*this);}

private:
    static bool _empruntable;
    int _numero;
    int _pages;
};

using vector_documents = std::vector<document*>;

class bibliotheque {
public:
    bibliotheque() =default;

    ~bibliotheque();

    document* ajouter(document const &d);

private:
    void delete_pointer(document* pointeur) const {delete pointeur;}
    vector_documents _documents;
};
