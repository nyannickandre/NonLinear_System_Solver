
#ifndef PCSC_PROJECT_NONLINEARSYSTEMS_H
#define PCSC_PROJECT_NONLINEARSYSTEMS_H

#include <ostream>
#include "Function.h"
#include <string>
#include "Exceptions.h"
#include <math.h>


/**
* This is the main class for solving a Non-Linear Equation of the form \f$ f(x)=0 \f$.
*/


class NonLinearEquation{
public:

    /// Default constructor for a NonLinearEquation
    NonLinearEquation();
    /// Default destructor for a NonLinearEquation
    virtual ~NonLinearEquation();


    /// Method to set the Function f
    void SetFunction(const Function &fun);
    /// Method to set the tolerance
    void SetTolerance(const double tolerance);
    /// Method to set the maximum number of iterations
    void SetMaxNumberIterations(const int maxNumberIt);


    /** \brief A virtual method to solve a non-linear equation.
      * \return Output a double which is a root of the equation.
      *
      * This method is virtual as the user can choose any of the implemented
      * numerical methods in the derived classes to solve the non-linear equation.
      */
    virtual double SolveEquation() = 0;


protected:
    Function f; ///< the Function
    double tol;  ///< the tolerance define the precision of the solution
    double n_max;  ///< the maximum number of iterations
};

#endif
