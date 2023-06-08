#include "function.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Please provide exactly 1 argument - function\n";
        return 1;
    }

    std::string input{argv[1]};
    std::cout << "DBG | " << input << "\n";

    try {
        auto fun = ElementaryFunction(input);
        print_function(fun);
        std::cout << " is a valid function\n";
    }
    catch(const std::exception& e) {
        std::cerr << input << " isn't a valid function\n";
    }
}