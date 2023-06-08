#ifndef COMMON_TYPES_HPP
#define COMMON_TYPES_HPP

#include <iostream>

enum function_type_t {
    constant = 0,
    power = 1,
    exponential = 2,
    // logarihtmic,
    natural_log = 3,
    trig_sin = 4,
    trig_cos = 5, /*
    trig_tan,
    trig_cot,
    trig_asin,
    trig_acos,
    trig_atan,
    trig_acot */
};

struct function_data {
    double multiplier;
    std::pair<bool, double> argument = {false, 0};
    std::pair<bool, double> base = {false, 0};
};

#endif