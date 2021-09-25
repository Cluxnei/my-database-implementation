#include "command.hpp"

bool command::is_valid() {
    return this->_syntax->is_valid();
}

std::string command::get_error() {
    return this->_syntax->get_error();
}