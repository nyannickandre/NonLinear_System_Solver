#include "Function_to_test.h"
#include "ExpFunction.h"
#include "LogFunction.h"


/**
 * This file is used to test two elements:
 * 1) the correct implementation of the harcoded functions: to check that the combinations of objects Function work
 *    and that they return the correct derivatives.
 * 2) the correct implementation of the numerical derivative: check that the numerical derivative is almost equal to
 *    the analytical derivative (the tolerance is very low).
 */

double sinusoid(double x) {return std::sin(x) + std::cos(x) ;}
double d_sinusoid(double x) {return std::cos(x) - std::sin(x) ;}

/// Test for + operator
TEST(Function_test, plus_operator) {
    for(int i = 0; i<1000; i++){
        double x = 2*M_PI*i/1000;

        // Test hardcoded functions --> analytical derivative
        ASSERT_NEAR(sinusoid(x),sinusoid_harcoded.CalculateValue(x), 0.0001);
        ASSERT_NEAR(d_sinusoid(x),sinusoid_harcoded.Prime(x), 0.0001);

        // Test numerical derivative
        ASSERT_NEAR(sinusoid(x),sinusoid_standard.CalculateValue(x), 0.0001);
        ASSERT_NEAR(d_sinusoid(x),sinusoid_standard.Prime(x), 0.0001);
    }
}



double exponential(double x) {return std::exp(x) * std::log(x) ;}
double d_exponential(double x) {return std::exp(x) * std::log(x) + std::exp(x) * 1/x ;}

Function expo_log_hardcoded = Expo * Log;
Function expo_log_standard = Function([](double x) {return std::log(x) * std::exp(x);});

/// Test for * operator
TEST(Function_test, multiplication_operator) {
    for(int i = 500; i<5000; i++){
        double x = 2*i/1000;

        // Test hardcoded functions --> analytical derivative
        ASSERT_NEAR(exponential(x),expo_log_hardcoded.CalculateValue(x), 0.0001);
        ASSERT_NEAR(d_exponential(x),expo_log_hardcoded.Prime(x), 0.0001);

        // Test numerical derivative
        ASSERT_NEAR(exponential(x),expo_log_standard.CalculateValue(x), 0.0001);
        ASSERT_NEAR(d_exponential(x),expo_log_standard.Prime(x), 0.0001);
    }
}
