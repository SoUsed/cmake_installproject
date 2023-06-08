#include "../common/function.hpp"
#include <math.h>
#include <fstream>
#include "../configparser/configparse.hpp"

ElementaryFunction derivative(const ElementaryFunction& function) {
    auto result = function;

    switch (function.type) {
            case exponential:
                if(function.data.argument.first) {
                    result.data.multiplier *= log(function.data.argument.second);
                }
                break;
            case power:
                if (result.data.argument.second == 1) {
                        result.type = constant;
                        break; 
                    }
                result.data.multiplier *= result.data.argument.second--;
                break;
            case natural_log:
                result.type = power;
                result.data.argument.second = -1;
                break;
            case trig_sin:
                result.type = trig_cos;
                break;
            case trig_cos:
                result.data.multiplier *= -1;
                result.type = trig_sin;
                break;
            case constant:
                result.data.multiplier = 0;
                break;
            default:
                result.data.multiplier *= log(result.data.base.second);
                break;
    }
    return result;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Please provide exactly 1 argument - function\n"; 
        return 1;
    }

    std::ifstream cFile("config/derivatives.conf");
    auto funcs = confread(cFile);

    std::string input{argv[1]};

    if (funcs.find(input) != funcs.end()) {
        std::cout << funcs[input] << " is a derivative of the input function\n";
        return 0;
    }

    try {
        auto fun = ElementaryFunction(input);
        print_function(derivative(fun));
        std::cout << " is a derivative of the input function\n";
    }
    catch(const std::exception& e) {
        std::cerr << input << " isn't a valid function\n";
    }
}