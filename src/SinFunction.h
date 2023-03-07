
#ifndef PCSC_PROJECT_SINFUNCTION_H
#define PCSC_PROJECT_SINFUNCTION_H
#include "Function.h"
#include <cmath>

/**
* This is a main class for the Function \f$ f(x)=sin(x) \f$.
*/
class SinFunction : public Function {

public:

    /// Default constructor for a SinFunction
    SinFunction();
    /// Default destructor for a SinFunction
    virtual ~SinFunction();

    /** Method to compute the derivative of \f$ sin(x) \f$ at point \f$ x=d \f$.
     * \param Point d is a double.
     */
    double Prime(double d) const override;

};


#endif //PCSC_PROJECT_SINFUNCTION_H
