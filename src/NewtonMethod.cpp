
#include "NewtonMethod.h"


NewtonMethod::NewtonMethod() {}

NewtonMethod::~NewtonMethod() {}

void NewtonMethod::SetIterativeFunction() {
    Function fprime = Function(f.GetDerivative());

    if ( std::abs(f.Prime(x0))<tol ) {
        std::cout << "WARNING: f'(x0) is very close to 0 so we "
                     "may overshoot the desired root (numerical difficulties).\n" << std::endl;
    };

    g = f / fprime ;}