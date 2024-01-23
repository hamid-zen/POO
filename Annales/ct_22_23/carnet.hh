#pragma once
#include "horaire.hh"
#include <vector>

class carnet
{
private:
    std::vector<std::unique_ptr<rdv>> _liste;
public:
    carnet();
};

class exception_carnet : public std::exception {
private:
    std::string _message;
public:
    exception_carnet(std::string const & message);
    const char* what() const noexcept ;
};
