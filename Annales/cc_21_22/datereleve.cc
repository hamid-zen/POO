#include "datereleve.hh"

datereleve::datereleve(unsigned int a, unsigned int m, unsigned int j, unsigned int h)
    : _annee(a)
    , _mois(m)
    , _jour(j)
    , _heure(h)
{}

std::string datereleve::tostring() const
{
    return std::to_string(_annee) + "." + std::to_string(_mois) + "." + std::to_string(_jour) + " "
           + std::to_string(_heure) + "h";
}

bool datereleve::comparememejour(const datereleve &d) const
{
    return (_annee == d._annee) && (_mois == d._mois) && (_jour == d._jour);
}

bool datereleve::compareavant(const datereleve &d) const
{
    return (_annee < d._annee) || (_annee == d._annee) && (_mois < d._mois)
           || (_annee == d._annee) && (_mois == d._mois) && (_jour < d._jour);
}

releve::releve(const datereleve &d)
    : _date(d)
{}

temp::temp(const datereleve &d, int temperature)
    : releve(d)
    , _temperature(temperature)
{}

std::string temp::tostring() const
{
    return date().tostring() + " " + typereleve() + " " + std::to_string(_temperature / 10.0) + "C";
}

prec::prec(const datereleve &d, const t_prec &t, int q)
    : releve(d)
    , _type(t)
    , _quantite(q)
{}

std::string prec::tostring() const
{
    std::string type;
    switch (_type) {
    case t_prec::neige:
        type = "Neige";
        break;
    case t_prec::pluie:
        type = "Pluie";
        break;
    case t_prec::grele:
        type = "Grele";
        break;
    default:
        break;
    }
    return date().tostring() + " " + typereleve() + " " + type + " " + std::to_string(_quantite)
           + "mm";
}

vent::vent(const datereleve &d, const t_direction &di)
    : releve(d)
    , _direction(di)
{}

std::string vent::tostring() const
{
    std::string direction;
    switch (_direction) {
    case t_direction::Nord:
        direction = "Nord";
        break;
    case t_direction::Sud:
        direction = "Sud";
        break;
    case t_direction::Est:
        direction = "Est";
        break;
    case t_direction::Ouest:
        direction = "Ouest";
        break;
    default:
        break;
    }
    return date().tostring() + " " + typereleve() + " " + direction;
}

//bool basereleves::ajout(const releve &r)
//{
//    // On commence par verifier les contreinte
//    for (std::list<releve>::iterator it = _listereleves.begin(); it != _listereleves.end(); it++) {
//        if ((it->typereleve() == "Température" || it->typereleve() == "Vent")
//            && (r.typereleve() == "Température" || r.typereleve() == "Vent")) {
//            // On verifie que c'est pas our la meme date
//            if (it->date().comparememejour(r.date()))
//                return false;
//        } else if ((it->typereleve() == "Vent" && r.typereleve() == "Vent")) {
//            if (it->date().comparememejour(r.date()) && it->direction() == r.direction())
//                return false;
//        }
//    }

//    // Ici donc on peut ajouter tranquillement
//    _listereleves.push_back(r);
//}

//void basereleves::sortirrecents(std::ostream &stream, const datereleve &d)
//{
//    for (std::list<releve>::iterator it = _listereleves.begin(); it != _listereleves.end(); it++) {
//        if (it->date().compareavant(d))
//            it->sortiesurflux(stream);
//    }
//}

//int basereleves::tempmoyenne(const datereleve &d) const
//{
//    int sum(0), count(0);

//    for (std::list<releve>::const_iterator it = _listereleves.begin(); it != _listereleves.end();
//         it++) {
//        if (it->typereleve() == "Temperature" && it->date().comparememejour(d)) {
//            sum += it->temperature();
//            count++;
//        }
//    }

//    return sum / count;
//}

datereleve basereleves::tempsdangereux() const
{
    for (std::list<releve>::const_iterator it = _listereleves.begin(); it != _listereleves.end();
         it++) {
        // On check si on a u
    }
}
