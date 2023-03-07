
#ifndef PCSC_PROJECT_FIXEDPOINT_H
#define PCSC_PROJECT_FIXEDPOINT_H


#include "IterativeMethod.h"

/**
* This class implements the Fixed-point method.
*/


class FixedPoint: public IterativeMethod {
public:

    /// Default constructor for a Fixed-point method
    FixedPoint();
    /// Default destructor for a Fixed-point method
    virtual ~FixedPoint();


    /// Method to set the iterative function as \f$ g(x)=f(x) \f$.
    void SetIterativeFunction() override;

    };


#endif //PCSC_PROJECT_FIXEDPOINT_H
