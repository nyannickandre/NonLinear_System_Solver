
#ifndef PCSC_PROJECT_ITERATIVEMETHOD_H
#define PCSC_PROJECT_ITERATIVEMETHOD_H

#include "NonLinearEquation.h"

/**
* This class is the base class for all iterative methods: Fixed-point, Newton, Chords.
*/


class IterativeMethod : public NonLinearEquation {
public:

    /// Default constructor for an IterativeMethod
    IterativeMethod();
    /// Default destructor for an IterativeMethod
    virtual ~IterativeMethod();


    //Set Methods

    /// Virtual method to set the iterative Function.
    /// Each method will have a different iteration function \f$ g \f$.
    virtual void SetIterativeFunction()=0;
    /// Method to set the starting point x0 of the iterative method.
    void SetStartingPoint(const double xn);
    /** Method to set the boolean Aitken.
    * If Aitken is true then the Aitken error estimation is used to accelerate convergence.
    */
    void SetAitken(const bool AitkenAcceleration);


    /** A method to solve a non-linear equation with an iterative scheme:
    * \f$ x_(n+1)= x_n - g(x_n) \f$
    */
    double SolveEquation() override;


protected:
    double x0;   ///< the initial point
    Function g;  ///< the iterative Function
    bool Aitken;  ///< the boolean for Aitken
};


#endif //PCSC_PROJECT_ITERATIVEMETHOD_H
