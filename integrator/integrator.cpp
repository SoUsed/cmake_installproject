#include "../common/function.hpp"
#include <math.h>
#include <fstream>
#include "../configparser/configparse.hpp"

ElementaryFunction integral(const ElementaryFunction& function) {
    auto result = function;

    switch (function.type) {
            case exponential:
                if(function.data.argument.first) {
                    result.data.multiplier /= log(function.data.argument.second);
                }
                break;
            case power:
                if (result.data.argument.second == -1) {
                        result.type = natural_log;
                        break; 
                    }
                result.data.multiplier /= ++result.data.argument.second;
                break;
            case natural_log:
                std::cerr << "ln(x) is too hard. No.\n";
                throw "ln(x)";
                break;
            case trig_sin:
                result.data.multiplier *= -1;
                result.type = trig_cos;
                break;
            case trig_cos:
                result.type = trig_sin;
                break;
            case constant:
                result.type = power;
                result.data.argument = {true, 1};
                break;
            default:
                result.data.multiplier /= log(result.data.base.second);
                break;
    }
    return result;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Please provide exactly 1 argument - function\n";
        return 1;
    }

    std::ifstream cFile("config/integrals.conf");
    auto funcs = confread(cFile);

    std::string input{argv[1]};

    if (funcs.find(input) != funcs.end()) {
        std::cout << funcs[input] << " is an integral of the input function\n";
        return 0;
    }
    try {
        auto fun = ElementaryFunction(input);
        print_function(integral(fun));
        std::cout << " is an integral of the input function\n";
    }
    catch(const std::exception& e) {
        std::cerr << input << " isn't a valid function\n";
    }
}