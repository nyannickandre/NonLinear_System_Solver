#include "Function_to_test.h"
#include <gtest/gtest.h>

/**
 * This file is used to test Chords method and its limits.
 */

/// Test of Chords method with function poly_deg1
TEST(Chords_test, poly_deg1) {    // root is -4
    ASSERT_NEAR(-4, NonLinearSolver(poly_deg1, "Chords", 0.000001, 1000, 8., true), 0.000001);
    ASSERT_THROW(NonLinearSolver(poly_deg1, "Chords", 0.000001, 1000, -10000000000000000., true), std::convergence_error);
}

/// Test of Chords method with function poly_deg2
TEST(Chords_test, poly_deg2) {    // roots are (1+std::sqrt(5))/2 and (1-std::sqrt(5))/2
    ASSERT_NEAR((1+std::sqrt(5))/2, NonLinearSolver(poly_deg2, "Chords", 0.000001, 1000, 10, true), 0.000001);
    ASSERT_NEAR((1-std::sqrt(5))/2, NonLinearSolver(poly_deg2, "Chords", 0.000001, 1000, -10., true), 0.000001);
    ASSERT_THROW(NonLinearSolver(poly_deg2, "Chords", 0.000001, 1000, -100., true), std::convergence_error);
}

/// Test of Chords method with function poly_deg3
TEST(Chords_test, poly_deg3) {   // root is -2.240040987469
    ASSERT_NEAR(-2.240040987469, NonLinearSolver(poly_deg3, "Chords", 0.000001, 1000, -10., true), 0.000001);
    ASSERT_THROW(NonLinearSolver(poly_deg3, "Chords", 0.000001, 1000, -100., true), std::convergence_error);
}

/// Test of Chords method with function sinusoid_harcoded
TEST(Chords_test, sinusoid_harcoded) {    // roots are -M_PI/4 mod M_PI
    ASSERT_NEAR(-M_PI/4, remainder(NonLinearSolver(sinusoid_harcoded, "Chords", 0.000001, 1000, 0.1, true),M_PI), 0.000001);
    ASSERT_THROW(NonLinearSolver(sinusoid_harcoded, "Chords", 0.000001, 1000, 10., true), std::convergence_error);
}

/// Test of Chords method with function sinusoid_standard
TEST(Chords_test, sinusoid_standard) {     // roots are -M_PI/4 mod M_PI
    ASSERT_NEAR(-M_PI/4, remainder(NonLinearSolver(sinusoid_standard, "Chords", 0.000001, 1000, 0.1, true),M_PI), 0.000001);
    ASSERT_THROW(NonLinearSolver(sinusoid_standard, "Chords", 0.000001, 1000, 10., true), std::convergence_error);}

/// Test of Chords method with function hyperbolic
TEST(Chords_test, hyperbolic) {    // root is 0
    ASSERT_NEAR(0, NonLinearSolver(hyperbolic, "Chords", 0.000001, 1000, 3., true), 0.000001);
    ASSERT_THROW(NonLinearSolver(hyperbolic, "Chords", 0.000001, 1000, 2., true), std::convergence_error);
}

/// Test of Chords method with function exponential_hardcoded
TEST(Chords_test, exponential_hardcoded) {     // root is 0.269874
    ASSERT_NEAR(0.269874, NonLinearSolver(exponential_hardcoded, "Chords", 0.000001, 1000, 4., true), 0.000001);
    ASSERT_THROW(NonLinearSolver(exponential_hardcoded, "Chords", 0.000001, 1000, 2., true), std::convergence_error);
}

/// Test of Chords method with function exponential_standard
TEST(Chords_test, exponential_standard) {    // root is 0.269874
    ASSERT_NEAR(0.269874, NonLinearSolver(exponential_standard, "Chords", 0.000001, 1000, 4., true), 0.000001);
    ASSERT_THROW(NonLinearSolver(exponential_standard, "Chords", 0.000001, 1000, 2., true), std::convergence_error);
}

/// Test of Chords method with function fun_random
TEST(Chords_test, fun_random) {   // root is -1.06052
    ASSERT_NEAR(-1.06052, NonLinearSolver(fun_random, "Chords", 0.000001, 1000, -5., true), 0.000001);
    ASSERT_NEAR(-1.06052, NonLinearSolver(fun_random, "Chords", 0.000001, 1000, 3., true), 0.00001);
    ASSERT_THROW(NonLinearSolver(fun_random, "Chords", 0.000001, 1000, -1., true), std::convergence_error);
}

/// Test of Chords method with function fun_random2
TEST(Chords_test, fun_random2) {   // roots are 0 mod M_PI
    ASSERT_NEAR(0, remainder(NonLinearSolver(fun_random2, "Chords", 0.000001, 1000, 0.01, true),M_PI), 0.000001);
    ASSERT_THROW(remainder(NonLinearSolver(fun_random2, "Chords", 0.000001, 1000, 0.4, true),M_PI), std::convergence_error);
}

