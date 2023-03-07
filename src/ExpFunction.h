
#ifndef PCSC_PROJECT_EXPFUNCTION_H
#define PCSC_PROJECT_EXPFUNCTION_H
#include "Function.h"
#include <cmath>

/**
* This is a main class for the Function \f$ f(x)=exp(x) \f$.
*/
class ExpFunction : public Function {

public:

    /// Default constructor for an ExpFunction
    ExpFunction();
    /// Default destructor for an ExpFunction
    virtual ~ExpFunction();

    /** Method to compute the derivative of \f$ exp(x) \f$ at point \f$ x=d \f$.
     * \param Point d is a double.
     */
    double Prime(double d) const override;

};


#endif //PCSC_PROJECT_EXPFUNCTION_H
