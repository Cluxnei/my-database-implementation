#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "command.hpp"

bool command::is_valid() {
    return this->_syntax->is_valid();
}

std::string command::get_error() {
    return this->_syntax->get_error();
}

void command::execute() {
    std::string command_type = this->_syntax->get_command_type();
    if (command_type == "SHOW DATABASES") {
        this->_show_databases();
    }
}

std::string command::get_output() {
    return this->_output_stream.str();
}

void command::_show_databases() {
    std::stringstream out;
    std::ifstream database_map("./database_map");
    std::string _, _database_name;
    int max_length = 0;
    while (database_map >> _ >> _database_name) {
        max_length = std::max(max_length, (int)_database_name.length());
        out << "| " << _database_name << " |" << std::endl;
    }
    database_map.close();
    this->_output_stream << "+" << std::string(max_length + 2, '-') << "+" << std::endl;
    this->_output_stream << out.str();
    this->_output_stream << "+" << std::string(max_length + 2, '-') << "+" << std::endl;
}