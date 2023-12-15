#pragma once
#include "position.hh"

#include <algorithm>
#include <memory>
#include <vector>

enum class t_couleur { blanc, noir };

using position_vector = std::vector<position>;

class piece
{
public:
    piece(t_couleur const &couleur, position const &position);

    t_couleur coul() const { return _couleur; }
    position pos() const { return _position; }

    virtual int valeur() const = 0;
    virtual char symbole() const = 0;

    std::string tostring() const;

    virtual position_vector deplacementspossibles() const =0;

    bool accepterposition(position const &p) const;

    bool deplacer(position const &destination);

    virtual std::unique_ptr<piece> clone() const = 0;

private:
    t_couleur _couleur;
    position _position;
};

class pion : public piece
{
public:
    pion(t_couleur const &couleur, position const &position);

    int valeur() const override { return __valeur; }
    char symbole() const override { return __symbole; }

    position_vector deplacementspossibles() const override; // Bon

    std::unique_ptr<piece> clone() const override { return std::make_unique<pion>(*this); }

private:
    static int __valeur;
    static char __symbole;
};

class cavalier : public piece
{
public:
    cavalier(t_couleur const &couleur, position const &position);

    int valeur() const override { return __valeur; }
    char symbole() const override { return __symbole; }

    position_vector deplacementspossibles() const override; // Bon

    std::unique_ptr<piece> clone() const override { return std::make_unique<cavalier>(*this); }

private:
    static int __valeur;
    static char __symbole;
};

class dame : public piece
{
public:
    dame(t_couleur const &couleur, position const &position);

    int valeur() const override { return __valeur; }
    char symbole() const override { return __symbole; }

    position_vector deplacementspossibles() const override ; // Bon
    std::unique_ptr<piece> clone() const override { return std::make_unique<dame>(*this); }

private:
    static int __valeur;
    static char __symbole;
};

class roi : public piece
{
public:
    roi(t_couleur const &couleur, position const &position);

    int valeur() const override { return __valeur; }
    char symbole() const override { return __symbole; }

    position_vector deplacementspossibles() const override; // Bon

    std::unique_ptr<piece> clone() const override { return std::make_unique<roi>(*this); }

private:
    static int __valeur;
    static char __symbole;
};
