#include <iostream>
#include <string>
#include <sstream>
#include "command.hpp"
#include <sys/stat.h>
#include <fstream>
#if defined(_WIN32)
#include <direct.h>   // _mkdir
#endif

std::string getInstructions();
std::string getOutputPrefix();
void createWorkDirectories();

int main() {
    createWorkDirectories();
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
        std::cout << cmd.get_output();
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

inline bool file_exists(const std::string& name) {
  struct stat buffer;
  return (stat(name.c_str(), &buffer) == 0); 
}

bool dir_exist(const std::string& path) {
    #if defined(_WIN32)
        struct _stat info;
        if (_stat(path.c_str(), &info) != 0) {
            return false;
        }
        return (info.st_mode & _S_IFDIR) != 0;
    #else 
        struct stat info;
        if (stat(path.c_str(), &info) != 0) {
            return false;
        }
        return (info.st_mode & S_IFDIR) != 0;
    #endif
}

void make_dir(const std::string& path) {
    #if defined(_WIN32)
    int ret = _mkdir(path.c_str());
    #else
        mode_t mode = 0755;
        int ret = mkdir(path.c_str(), mode);
    #endif
}

void createWorkDirectories() {
    if (!file_exists("./database_map")) {
        std::ofstream database_map("./database_map");
        database_map << "";
        database_map.close();
    }
    if (!dir_exist("./databases")) {
        make_dir("./databases");
    }
}