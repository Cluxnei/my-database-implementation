#include <string>
#include <sstream>
#include "syntax.hpp"

class command {
    public:
        command(std::string _command) {
            this->_command = _command;
            this->_syntax = new syntax(_command);
        }
        bool is_valid();
        std::string get_error();
        void execute();
        std::string get_output();
    private:
        std::string _command;
        std::stringstream _output_stream;
        syntax *_syntax;
        void _show_databases();
};