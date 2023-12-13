#pragma once
#include <iostream>
#include <list>
#include <string>

class datereleve
{
private:
    unsigned int _annee;
    unsigned int _mois;
    unsigned int _jour;
    unsigned int _heure;

public:
    datereleve(unsigned int a, unsigned int m, unsigned int j, unsigned int h);

    std::string tostring() const;

    bool comparememejour(datereleve const &d) const;
    bool compareavant(datereleve const &d) const;
};

class releve
{
private:
    datereleve _date;

public:
    releve(datereleve const &d);

    datereleve date() const { return _date; }
    virtual std::string typereleve() const = 0;
    virtual std::string tostring() const = 0;

    void sortiesurflux(std::ostream &stream) const { stream << tostring(); }
};

class temp : public releve
{
private:
    int _temperature;

public:
    temp(datereleve const &d, int temperature);

    int temperature() const { return _temperature; }

    std::string typereleve() const override { return "Température"; }
    std::string tostring() const override;
};

enum class t_prec { pluie, grele, neige };

class prec : public releve
{
private:
    t_prec _type;
    int _quantite;

public:
    prec(datereleve const &d, t_prec const &t, int q);

    std::string typereleve() const override { return "Précipitations"; }
    std::string tostring() const override;

    t_prec type() const { return _type; }
};

enum class t_direction { Nord, Sud, Est, Ouest };

class vent : public releve
{
private:
    t_direction _direction;

public:
    vent(datereleve const &d, t_direction const &di);

    std::string typereleve() const override { return "Vent"; }
    std::string tostring() const override;
};

class basereleves
{
private:
    std::list<releve> _listereleves;

public:
    basereleves() = default;

    // A partir d'ici
    bool ajout(releve const &r);

    void sortirrecents(std::ostream &stream, datereleve const &d);

    int tempmoyenne(datereleve const &d) const;

    datereleve tempsdangereux() const;
};
