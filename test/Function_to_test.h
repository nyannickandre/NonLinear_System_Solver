#ifndef PCSC_PROJECT_FUNCTION_TO_TEST_H
#define PCSC_PROJECT_FUNCTION_TO_TEST_H

#include <cmath>
#include <functional>
#include "Function.h"
#include "NonLinearSolver.h"
#include "gtest/gtest.h"
#include "CosFunction.h"
#include "SinFunction.h"
#include "ExpFunction.h"
#include "LogFunction.h"
#include <math.h>

/**
 * This header file is made to create the function that will be solved when testing
 * if the NonLinearSolver returns the correct results or exception when it is called
 * with these Functions as argument.
 */

/// The first Function is a simple linear function
Function poly_deg1 = Function([](double x){return x + 4;});

/// The second Function is a polynomial of degree 2
Function poly_deg2 = Function([](double x){return x*x - x - 1;});

/// The third Function is a polynomial of degree 3
Function poly_deg3 = Function([](double x){return x*x*x -x + 9;});

/// This fourth Function is a sum of sinusoidal functions using the hardcoded version of sin and cos (with analytical derivative)
CosFunction cosine;
SinFunction sine;

Function sinusoid_harcoded = cosine + sine;

/// This fifth Function is a sum of sinusoidal functions using the standard version of sin and cos (with numerical derivative)
Function sinusoid_standard = Function([](double x) {return std::cos(x) + std::sin(x) ;});

/// The 6th Function is an hyperbolic function
Function hyperbolic = Function([](double x) {return std::cosh(x) -1 ;});


/// The 7th Function is an exponential/logarithmic function using the hardcoded version of exp and log (with analytical derivative)
ExpFunction Expo;
LogFunction Log;

Function exponential_hardcoded = Expo + Log;

/// The 8th Function is an exponential/logarithmic function using the standard version of exp and log (with numerical derivative)
Function exponential_standard = Function([](double x) {return std::log(x) + std::exp(x);});

/// The 9th Function is a random function
Function fun_random = Function([](double x) {return std::abs(cos(x)*cos(x)+0.2*x*x*x);});

/// The 10th Function is a another random function
Function fun_random2 = Function([](double x) {return std::abs(log(1+sin(x)));});


#endif //PCSC_PROJECT_FUNCTION_TO_TEST_H
