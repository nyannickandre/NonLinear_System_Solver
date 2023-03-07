#include "Function_to_test.h"
#include <gtest/gtest.h>

/**
 * This file is used to test Newton method and its limits.
 */

/// Test of Newton method with function poly_deg1
TEST(Newton_test, poly_deg1) {    // root is -4
    ASSERT_NEAR(-4, NonLinearSolver(poly_deg1, "Newton", 0.000001, 1000, 8., true), 0.000001);
    ASSERT_THROW(NonLinearSolver(poly_deg1, "Newton", 0.000001, 1000, -10000000000000000., true), std::convergence_error);
}

/// Test of Newton method with function poly_deg2
TEST(Newton_test, poly_deg2) {    // roots are (1+std::sqrt(5))/2 and (1-std::sqrt(5))/2
    ASSERT_NEAR((1+std::sqrt(5))/2, NonLinearSolver(poly_deg2, "Newton", 0.000001, 1000, 40, true), 0.000001);
    ASSERT_NEAR((1-std::sqrt(5))/2, NonLinearSolver(poly_deg2, "Newton", 0.000001, 1000, -50., true), 0.000001);
    ASSERT_THROW(NonLinearSolver(poly_deg2, "Newton", 0.000001, 1000, -10000000., true), std::convergence_error);
}

/// Test of Newton method with function poly_deg3
TEST(Newton_test, poly_deg3) {   // root is -2.240040987469
    ASSERT_NEAR(-2.240040987469, NonLinearSolver(poly_deg3, "Newton", 0.000001, 1000, -100., true), 0.000001);
    ASSERT_THROW(NonLinearSolver(poly_deg3, "Newton", 0.000001, 10, -100., true), std::convergence_error);
}

/// Test of Newton method with function sinusoid_harcoded
TEST(Newton_test, sinusoid_harcoded) {    // roots are -M_PI/4 mod M_PI
    ASSERT_NEAR(-M_PI/4, remainder(NonLinearSolver(sinusoid_harcoded, "Newton", 0.000001, 1000, 3., true),M_PI), 0.000001);
    ASSERT_THROW(NonLinearSolver(sinusoid_harcoded, "Newton", 0.000001, 3, 10., true), std::convergence_error);
}

/// Test of Newton method with function sinusoid_standard
TEST(Newton_test, sinusoid_standard) {     // roots are -M_PI/4 mod M_PI
    ASSERT_NEAR(-M_PI/4, remainder(NonLinearSolver(sinusoid_standard, "Newton", 0.000001, 1000, 3., true),M_PI), 0.000001);
    ASSERT_THROW(NonLinearSolver(sinusoid_standard, "Newton", 0.000001, 3, 10., true), std::convergence_error);}

/// Test of Newton method with function hyperbolic
TEST(Newton_test, hyperbolic) {    // root is 0
    ASSERT_NEAR(0, NonLinearSolver(hyperbolic, "Newton", 0.000001, 1000, 3., true), 0.01);
    ASSERT_THROW(NonLinearSolver(hyperbolic, "Newton", 0.000001, 1000, 20., true), std::convergence_error);
}

/// Test of Newton method with function exponential_hardcoded
TEST(Newton_test, exponential_hardcoded) {     // root is 0.269874
    ASSERT_NEAR(0.269874, NonLinearSolver(exponential_hardcoded, "Newton", 0.000001, 1000, 4., true), 0.000001);
    ASSERT_THROW(NonLinearSolver(exponential_hardcoded, "Newton", 0.000001, 1000, 2., true), std::convergence_error);
}

/// Test of Newton method with function exponential_standard
TEST(Newton_test, exponential_standard) {    // root is 0.269874
    ASSERT_NEAR(0.269874, NonLinearSolver(exponential_standard, "Newton", 0.000001, 1000, 4., true), 0.000001);
    ASSERT_THROW(NonLinearSolver(exponential_standard, "Newton", 0.000001, 1000, 2., true), std::convergence_error);
}

/// Test of Newton method with function fun_random
TEST(Newton_test, fun_random) {   // root is -1.06052
    ASSERT_NEAR(-1.06052, NonLinearSolver(fun_random, "Newton", 0.000001, 1000, -5., true), 0.00001);
    ASSERT_NEAR(-1.06052, NonLinearSolver(fun_random, "Newton", 0.000001, 1000, 3., true), 0.00001);
    ASSERT_THROW(NonLinearSolver(fun_random, "Newton", 0.000001, 100, 10., true), std::convergence_error);
}

/// Test of Newton method with function fun_random2
TEST(Newton_test, fun_random2) {   // roots are 0 mod M_PI
    ASSERT_NEAR(0, remainder(NonLinearSolver(fun_random2, "Newton", 0.000001, 1000, 18., true),M_PI), 0.000001);
    ASSERT_THROW(remainder(NonLinearSolver(fun_random2, "Newton", 0.000001, 1000, -M_PI/2, true),M_PI), std::convergence_error);
}

