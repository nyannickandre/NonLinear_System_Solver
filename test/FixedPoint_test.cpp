#include "Function_to_test.h"
#include <gtest/gtest.h>

/**
 * This file is used to test Fixed-point method and its limits.
 */

/// Test of Fixed-point method with function poly_deg1
TEST(FixedPoint_test, poly_deg1) {    // root is -4
    ASSERT_NEAR(-4, NonLinearSolver(poly_deg1, "FixedPoint", 0.000001, 1000, 8., true), 0.000001);
}

/// Test of Fixed-point method with function poly_deg2
TEST(FixedPoint_test, poly_deg2) {    // roots are (1+std::sqrt(5))/2 and (1-std::sqrt(5))/2
    ASSERT_THROW(NonLinearSolver(poly_deg2, "FixedPoint", 0.000001, 1000, 1., true), std::convergence_error);
}

/// Test of Fixed-point method with function poly_deg3
TEST(FixedPoint_test, poly_deg3) {   // root is -2.240040987469
    ASSERT_THROW(NonLinearSolver(poly_deg3, "FixedPoint", 0.000001, 10, -0., true), std::convergence_error);
}

/// Test of Fixed-point method with function sinusoid_harcoded
TEST(FixedPoint_test, sinusoid_harcoded) {    // roots are -M_PI/4 mod M_PI
    ASSERT_NEAR(-M_PI/4, remainder(NonLinearSolver(sinusoid_harcoded, "FixedPoint", 0.000001, 1000, 3., true),M_PI), 0.000001);
    ASSERT_THROW(NonLinearSolver(sinusoid_harcoded, "FixedPoint", 0.000001, 3, 10., true), std::convergence_error);
}

/// Test of Fixed-point method with function sinusoid_standard
TEST(FixedPoint_test, sinusoid_standard) {     // roots are -M_PI/4 mod M_PI
    ASSERT_NEAR(-M_PI/4, remainder(NonLinearSolver(sinusoid_standard, "FixedPoint", 0.000001, 1000, 3., true),M_PI), 0.000001);
    ASSERT_THROW(NonLinearSolver(sinusoid_standard, "FixedPoint", 0.000001, 3, 10., true), std::convergence_error);}

/// Test of Fixed-point method with function hyperbolic
TEST(FixedPoint_test, hyperbolic) {    // root is 0
    ASSERT_NEAR(0, NonLinearSolver(hyperbolic, "FixedPoint", 0.000001, 1000, 3., true), 0.01);
    ASSERT_THROW(NonLinearSolver(hyperbolic, "FixedPoint", 0.000001, 1000, 20., true), std::convergence_error);
}

/// Test of Fixed-point method with function exponential_hardcoded
TEST(FixedPoint_test, exponential_hardcoded) {     // root is 0.269874
    ASSERT_THROW(NonLinearSolver(exponential_hardcoded, "FixedPoint", 0.000001, 1000, 2., true), std::convergence_error);
}

/// Test of Fixed-point method with function exponential_standard
TEST(FixedPoint_test, exponential_standard) {    // root is 0.269874
    ASSERT_THROW(NonLinearSolver(exponential_standard, "FixedPoint", 0.000001, 1000, 2., true), std::convergence_error);
}

/// Test of Fixed-point method with function fun_random
TEST(FixedPoint_test, fun_random) {   // root is -1.06052
    ASSERT_THROW(NonLinearSolver(fun_random, "FixedPoint", 0.000001, 100, -2., true), std::convergence_error);
    ASSERT_THROW(NonLinearSolver(fun_random, "FixedPoint", 0.000001, 100, 1., true), std::convergence_error);
}

/// Test of Fixed-point method with function fun_random2
TEST(FixedPoint_test, fun_random2) {   // roots are 0 mod M_PI
    ASSERT_NEAR(0, remainder(NonLinearSolver(fun_random2, "FixedPoint", 0.000001, 1000, 18., true),M_PI), 0.000001);
    ASSERT_THROW(remainder(NonLinearSolver(fun_random2, "FixedPoint", 0.000001, 1000, -M_PI/2, true),M_PI), std::convergence_error);
}
