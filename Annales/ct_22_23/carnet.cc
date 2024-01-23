#include "carnet.hh"

carnet::carnet()
    : _liste() {}

exception_carnet::exception_carnet(const std::string &message)
    : _message(message) {}

const char *exception_carnet::what() const noexcept
{
    return _message.c_str();
}
