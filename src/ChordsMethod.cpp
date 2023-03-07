
#include "ChordsMethod.h"

ChordsMethod::ChordsMethod() {}

ChordsMethod::~ChordsMethod() {}

void ChordsMethod::SetIterativeFunction() {
    double denom;
    denom = 1 / f.Prime(x0);

    if ( std::abs(f.Prime(x0))<tol ) {
        std::cout << "WARNING: f'(x0) is very close to 0 so we "
                     "may overshoot the desired root (numerical difficulties).\n" << std::endl;
    };

    g = f * denom;}