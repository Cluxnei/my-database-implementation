#include <string>

class syntax {
    public:
        syntax(std::string _command) {
            this->_command_type = "undefined";
            this->_command = _command;
        }
        bool is_valid();
        std::string get_command_type();
        std::string get_error();
        std::string compute_command_type();
    private:
        std::string _valid_commands_types[2] = {
            "SHOW DATABASES",
            "SHOW TABLES"
        };
        std::string _command;
        std::string _command_type;
        std::string _error;
        std::string _error_syntax_message = "invalid syntax";
};
