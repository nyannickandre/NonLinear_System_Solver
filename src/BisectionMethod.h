
#ifndef PCSC_PROJECT_BISECTIONMETHOD_H
#define PCSC_PROJECT_BISECTIONMETHOD_H

#include "NonLinearEquation.h"
#include <ostream>

/**
* This class implements the Bisection method.
*/

class BisectionMethod : public NonLinearEquation {
public:

    /// Default constructor for a Bisection method
    BisectionMethod();
    /// Default destructor for a Bisection method
    virtual ~BisectionMethod();


    /** \brief Method to set the interval.
      * \param x can be the lower or upper bound of the interval.
      * \param y is the other bound.
      */
    void SetInterval(double a, double b);


    /** \brief Method to solve the non-linear equation.
     * This method is virtual as the user can choose any of the implemented
     * numerical methods in the derived classes to solve the non-linear equation.
    */
    double SolveEquation() override;


protected:
 double x;  ///< the lower bound of the interval
 double y;  ///< the upper bound of the interval
};


#endif //PCSC_PROJECT_BISECTIONMETHOD_H
