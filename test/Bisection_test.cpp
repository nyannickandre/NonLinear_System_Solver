#include "Function_to_test.h"
#include <gtest/gtest.h>

/**
 * This file is used to test Bisection method and its limits.
 */

/// Test of Bisection method with function poly_deg1
TEST(Bisection_test, poly_deg1) {    // root is -4
    ASSERT_NEAR(-4, NonLinearSolver(poly_deg1, "Bisection", 0.000001, 1000, -5., 10.), 0.000001);
    ASSERT_NEAR(-4,NonLinearSolver(poly_deg1, "Bisection", 0.000001, 1000, -10000000000000000., 0.), 0.000001);
}

/// Test of Bisection method with function poly_deg2
TEST(Bisection_test, poly_deg2) {    // roots are (1+std::sqrt(5))/2 and (1-std::sqrt(5))/2
    ASSERT_NEAR((1+std::sqrt(5))/2, NonLinearSolver(poly_deg2, "Bisection", 0.000001, 1000, 0.2, 10.), 0.000001);
    ASSERT_NEAR((1-std::sqrt(5))/2,NonLinearSolver(poly_deg2, "Bisection", 0.000001, 1000, -40., 0.), 0.000001);
    ASSERT_THROW(NonLinearSolver(poly_deg2, "Bisection", 0.000001, 1000, -10.,10.), std::domain_error);
}

/// Test of Bisection method with function poly_deg3
TEST(Bisection_test, poly_deg3) {   // root is -2.240040987469
    ASSERT_NEAR(-2.240040987469, NonLinearSolver(poly_deg3, "Bisection", 0.000001, 1000, -10., 1.), 0.000001);
    ASSERT_THROW(NonLinearSolver(poly_deg3, "Bisection", 0.000001, 1000, 0.,10.), std::domain_error);
}

/// Test of Bisection method with function sinusoid_harcoded
TEST(Bisection_test, sinusoid_harcoded) {    // roots are -M_PI/4 mod M_PI
    ASSERT_NEAR(-M_PI/4, remainder(NonLinearSolver(sinusoid_harcoded, "Bisection", 0.000001, 1000, 2., 10.),M_PI), 0.000001);
    ASSERT_THROW(NonLinearSolver(poly_deg3, "Bisection", 0.000001, 1000, 0.4, 7.5), std::domain_error);
}

/// Test of Bisection method with function sinusoid_standard
TEST(Bisection_test, sinusoid_standard) {     // roots are -M_PI/4 mod M_PI
    ASSERT_NEAR(-M_PI/4, remainder(NonLinearSolver(sinusoid_standard, "Bisection", 0.000001, 1000, 2., 10.),M_PI), 0.000001);
}

/// Test of Bisection method with function hyperbolic
TEST(Bisection_test, hyperbolic) {    // root is 0
    ASSERT_THROW(NonLinearSolver(hyperbolic, "Bisection", 0.000001, 1000, 2., 10.), std::domain_error);
}

/// Test of Bisection method with function exponential_hardcoded
TEST(Bisection_test, exponential_hardcoded) {     // root is 0.269874
    ASSERT_NEAR(0.269874, NonLinearSolver(exponential_hardcoded, "Bisection", 0.000001, 1000, 0.01, 10.), 0.000001);
    ASSERT_THROW(NonLinearSolver(exponential_hardcoded, "Bisection", 0.000001, 1000, -2., 7.5), std::convergence_error);
}

/// Test of Bisection method with function exponential_standard
TEST(Bisection_test, exponential_standard) {    // root is 0.269874
    ASSERT_NEAR(0.269874, NonLinearSolver(exponential_standard, "Bisection", 0.000001, 1000, 0.01, 10.), 0.000001);
}

/// Test of Bisection method with function fun_random
TEST(Bisection_test, fun_random) {   // root is -1.06052
    ASSERT_THROW(NonLinearSolver(fun_random, "Bisection", 0.000001, 1000, -10., 10.), std::domain_error);
}

/// Test of Bisection method with function fun_random2
TEST(Bisection_test, fun_random2) {   // roots are M_PI mod M_PI
    ASSERT_THROW(remainder(NonLinearSolver(fun_random2, "Bisection", 0.000001, 1000, 2., 10.),M_PI), std::domain_error);
}
