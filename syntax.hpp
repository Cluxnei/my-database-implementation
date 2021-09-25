#include <string>

class syntax {
    public:
        syntax(std::string _command) {
            this->_command = _command;
        }
        bool is_valid();
        std::string get_error();
    private:
        std::string _valid_commands[2] = {
            "SHOW DATABASES;",
            "SHOW TABLES;"
        };
        std::string _command;
        std::string _error;
        std::string _error_syntax_message = "invalid syntax";
};
