#include "syntax.hpp"

bool syntax::is_valid() {
    for(std::string _valid_command : this->_valid_commands) {
        if(this->_command == _valid_command) {
            return true;
        }
    }
    this->_error = this->_error_syntax_message;
    return false;
}

std::string syntax::get_error() {
    return this->_error == "" ? "unknow error" : this->_error;
}