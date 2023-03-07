
#ifndef PCSC_PROJECT_LOGFUNCTION_H
#define PCSC_PROJECT_LOGFUNCTION_H
#include "Function.h"
#include <cmath>

/**
* This is a main class for the Function \f$ f(x)=log(x) \f$.
*/
class LogFunction : public Function {

public:

    /// Default constructor for a LogFunction
    LogFunction();
    /// Default destructor for a LogFunction
    virtual ~LogFunction();

    /** Method to compute the derivative of \f$ log(x) \f$ at point \f$ x=d \f$.
     * \param Point d is a double.
     */
    double Prime(double d) const override;

};


#endif //PCSC_PROJECT_LOGFUNCTION_H
