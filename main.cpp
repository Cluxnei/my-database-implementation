#include <iostream>
#include <string>
#include <sstream>

std::string getInstructions();

int main() {

    std::cout << getInstructions() << std::endl;
    std::string input;
    while (true) {
        std::cout << "[root] > ";
        std::cin >> input;
        
        if (input == "q") {
            break;
        }
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