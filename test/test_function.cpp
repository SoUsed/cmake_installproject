#include <gtest/gtest.h>
#include "function.hpp"
#include "types.hpp"

TEST(function, power) {
    std::string f1 = "x^2";
    std::string f2 = "-0.7x^0.26";
    std::string f3 = "3x^(-2)";
    EXPECT_EQ(ElementaryFunction(f1).type, function_type_t::power);
    EXPECT_EQ(ElementaryFunction(f2).type, function_type_t::power);
    EXPECT_EQ(ElementaryFunction(f3).type, function_type_t::power);
}

TEST(function, exponent) {
    std::string f1 = "e^x";
    std::string f2 = "7.2*e^x";
    std::string f3 = "1*2^x";
    std::string f4 = "-5*3.7^x";
    EXPECT_EQ(ElementaryFunction(f1).type, function_type_t::exponential);
    EXPECT_EQ(ElementaryFunction(f2).type, function_type_t::exponential);
    EXPECT_EQ(ElementaryFunction(f3).type, function_type_t::exponential);
    EXPECT_EQ(ElementaryFunction(f4).type, function_type_t::exponential);
}

TEST(function, trig) {
    std::string f1 = "sin(x)";
    std::string f2 = "-4cos(x)";
    EXPECT_EQ(ElementaryFunction(f1).type, function_type_t::trig_sin);
    EXPECT_EQ(ElementaryFunction(f2).type, function_type_t::trig_cos);
}

TEST(function, logarithm) {
    std::string f1 = "ln(x)";
    std::string f2 = "-1.7ln(x)";
    EXPECT_EQ(ElementaryFunction(f1).type, function_type_t::natural_log);
    EXPECT_EQ(ElementaryFunction(f2).type, function_type_t::natural_log);
}

TEST(function, constants) {
    std::string f1 = "1.23";
    std::string f2 = "-44";
    EXPECT_EQ(ElementaryFunction(f1).type, function_type_t::constant);
    EXPECT_EQ(ElementaryFunction(f2).type, function_type_t::constant);
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}