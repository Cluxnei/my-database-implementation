#include <string>
#include "syntax.hpp"

class command {
    public:
        command(std::string _command) {
            this->_command = _command;
            this->_syntax = new syntax(_command);
        }
        bool is_valid();
        std::string get_error();
    private:
        std::string _command;
        syntax *_syntax;
};