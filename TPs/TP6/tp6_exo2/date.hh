#pragma once

#include <iostream>
class date
{
public:

    date(unsigned int const &annee, unsigned int const &mois, unsigned int const &jour);

    unsigned int annee() const;

    unsigned int mois() const;

    unsigned int jour() const;

    date & operator = (date const &d);
    bool operator == (date const &d) const;
    bool operator < (date const &d) const;

    std::ostream & sortieflux(std::ostream &s) const;

private:
    unsigned int _annee;
    unsigned int _mois;
    unsigned int _jour;
};

std::ostream &operator << (std::ostream &s, date const &d);
