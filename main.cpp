#include <iostream>
#include <string>
#include <sstream>
#include "command.hpp"

std::string getInstructions();
std::string getOutputPrefix();

int main() {

    std::cout << getInstructions() << std::endl;
    std::string input;
    while (true) {
        std::cout << getOutputPrefix();
        std::getline(std::cin, input);
        if (input == "q") {
            break;
        }
        command cmd(input);
        if (!cmd.is_valid()) {
            std::cout << cmd.get_error() << std::endl;
            continue;
        }
        cmd.execute();
        
    }
    std::cout << "Bye bye, see u soon!" << std::endl;
    return 0;
}

std::string getInstructions() {
    std::stringstream ss;
    ss << "Instructions:" << std::endl;
    ss << "   - Available commands: " << std::endl;
    ss << "      - CREATE DATABASE <database name>;" << std::endl;
    ss << "      - USE <database name>;" << std::endl;
    ss << "      - SHOW DATABASES;" << std::endl;
    ss << "      - CREATE TABLE <table name> (<collumn name> <data type> <NULL or NOT NULL>);" << std::endl;
    ss << "   - Available data types:" << std::endl;
    ss << "      - INT" << std::endl;
    ss << "      - STRING" << std::endl;
    ss << "      - FLOAT" << std::endl;
    ss << "   - Type 'q' to quit" << std::endl;
    return ss.str();
}

std::string getOutputPrefix() {
    return "[root] > ";
}