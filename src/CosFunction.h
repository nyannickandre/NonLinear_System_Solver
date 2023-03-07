
#ifndef PCSC_PROJECT_COSFUNCTION_H
#define PCSC_PROJECT_COSFUNCTION_H
#include "Function.h"
#include <cmath>

/**
* This is a main class for the Function \f$ f(x)=cos(x) \f$.
*/
class CosFunction : public Function {

public:

    /// Default constructor for a CosFunction
    CosFunction();
    /// Default destructor for a CosFunction
    virtual ~CosFunction();

    /** Method to compute the derivative of \f$ cos(x) \f$ at point \f$ x=d \f$.
     * \param Point d is a double.
     */
    double Prime(double d) const override;

};


#endif //PCSC_PROJECT_COSFUNCTION_H
