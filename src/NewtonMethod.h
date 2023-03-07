
#ifndef PCSC_PROJECT_NEWTONMETHOD_H
#define PCSC_PROJECT_NEWTONMETHOD_H


#include "IterativeMethod.h"

/**
* This class implements the Newton method.
*/


class NewtonMethod: public IterativeMethod {
public:

    /// Default constructor for a Newton method
    NewtonMethod();
    /// Default destructor for a Newton method
    virtual ~NewtonMethod();

    /// Method to set the iterative function as \f$ g(x)=\frac{f(x)}{df(x)} \f$.
    void SetIterativeFunction() override;

};
#endif //PCSC_PROJECT_NEWTONMETHOD_H