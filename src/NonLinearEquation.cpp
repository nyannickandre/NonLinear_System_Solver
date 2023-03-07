
#include "NonLinearEquation.h"

// Constructor and destructor
NonLinearEquation::NonLinearEquation()
        : f(), tol(), n_max() {}
NonLinearEquation::~NonLinearEquation() {}

// Set methods
void NonLinearEquation::SetFunction(const Function &fun) { f = fun; }
void NonLinearEquation::SetTolerance(const double tolerance) { tol = tolerance; }
void NonLinearEquation::SetMaxNumberIterations(const int maxNumberIt) { n_max = maxNumberIt; }
