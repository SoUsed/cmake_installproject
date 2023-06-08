#ifndef COMMON_FUNCTION_HPP
#define COMMON_FUNCTION_HPP

#include <vector>
#include "types.hpp"
#include <regex>
#include <map>
#include <exception>

const std::string ELEMENTARY_FUNCTION_REGEX = "([0-9-.]{0,})[*]{0,1}([a-zA-Z0-9.]{0,})([(^]{0,})([a-zA-Z0-9.-]{0,})[)]{0,1}";

std::map<std::string, function_type_t> FUNCTION_STRINGS = {
    {"", constant},
    {"x", power},
    {"e", exponential},
    {"ln", natural_log},
    {"sin", trig_sin},
    {"cos", trig_cos},
}; // any numeric is also exponential

std::map<function_type_t, std::string> FUNCTION_TO_STRING = {
    {constant, ""},
    {power, "x"},
    {exponential, "e"},
    {natural_log, "ln"},
    {trig_sin, "sin"},
    {trig_cos, "cos"},
}; // any numeric is also exponential

struct ElementaryFunction {
    function_type_t type;
    function_data data;

    ElementaryFunction(const std::string& notation) {
        std::cout << "processing " << notation << "\n";
        std::regex efun_regex(ELEMENTARY_FUNCTION_REGEX, std::regex_constants::icase);
        std::smatch sm;
        auto match = std::regex_match(notation, sm, efun_regex);

        if(!match) {
            std::cerr << "Invalid function!\n";
            throw std::exception();
        }

        auto mult_str = sm.str(1);
        double mult = mult_str == "" ? 1 : std::stod(mult_str);
        auto funname = sm.str(2);
        auto funarg = sm.str(4);

        data.multiplier = mult;
        
        if (FUNCTION_STRINGS.find(funname) != FUNCTION_STRINGS.end() && funname != "")
            type = FUNCTION_STRINGS[funname];
        else {
            if (notation.find("^") != std::string::npos) {
                std::cout << mult << " " << funname << " " << funarg << "\n";
                type = exponential;
                data.argument = {true, std::stod(funname)};
            }
            else {
                type = constant;
            }
        }

        switch (type) {
            case exponential:
                break;
            case power:
            case natural_log:
            case trig_sin:
            case trig_cos:
                data.argument = {true, funarg == "" ? std::stod(funarg) : 0};
            case constant:
                break;
            default:
                data.base = {true, funname == "" ? std::stod(funname) : 0};
                break;
        }
    }

    ElementaryFunction() {}
};

void print_function(const ElementaryFunction& function) {
    std::string ret;
    switch (function.type) {
        case exponential:
            ret = function.data.argument.first ? std::to_string(function.data.argument.second) : "e";
            ret += "^x";
            break;
        case power:
            ret = FUNCTION_TO_STRING[function.type] + "^" + std::to_string(function.data.argument.second);
            break;
        case natural_log:
        case trig_sin:
        case trig_cos:
            ret = FUNCTION_TO_STRING[function.type] + "(x)";
            break;
        case constant:
            break;
        default:
            ret = std::to_string(function.data.argument.second) + "^x";
    }
    std::cout << function.data.multiplier << ret;
}

#endif