#include "date.hh"

date::date(const unsigned int &annee, const unsigned int &mois, const unsigned int &jour)
    : _annee(annee), _mois(mois), _jour(jour) {}

unsigned int date::jour() const
{
    return _jour;
}

date &date::operator =(const date &d)
{
    _annee = d._annee;
    _mois = d._mois;
    _jour = d._jour;

    return *this;
}

bool date::operator ==(const date &d) const
{
    return (_annee == d.annee() && _mois == d.mois() && _jour == d.jour());
}

bool date::operator < (const date &d) const
{
    return (_annee < d.annee()) || (_annee == d.annee() && _mois < d.mois()) || (_annee == d.annee() && _mois == d.mois() && _jour < d.jour());
}

std::ostream &date::sortieflux(std::ostream &s) const
{
    s << _jour << "/" << _mois << "/" << _annee;
    return s;
}

unsigned int date::mois() const
{
    return _mois;
}

unsigned int date::annee() const
{
    return _annee;
}

std::ostream &operator << (std::ostream &s, date const &d) {
    d.sortieflux(s);
    return s;
}
