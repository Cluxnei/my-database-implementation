#include "syntax.hpp"

bool syntax::is_valid() {
    std::string _command_type = this->compute_command_type();
    for(std::string _valid_command_type : this->_valid_commands_types) {
        if(_command_type == _valid_command_type) {
            return true;
        }
    }
    this->_error = this->_error_syntax_message;
    return false;
}

std::string syntax::get_error() {
    return this->_error == "" ? "unknow error" : this->_error;
}

std::string syntax::get_command_type() {
    return this->_command_type;
}

std::string syntax::compute_command_type() {
    this->_command_type = "undefined";
    if (this->_command == "SHOW DATABASES;") {
        this->_command_type = "SHOW DATABASES";
    }
    return this->_command_type;
}