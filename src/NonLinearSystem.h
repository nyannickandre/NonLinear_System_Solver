
#ifndef PCSC_PROJECT_NONLINEARSYSTEM_H
#define PCSC_PROJECT_NONLINEARSYSTEM_H

#include "NonLinearEquation.h"
#include "Function2D.h"

/**
 * This is a class to solve a non linear of two equations and two unknowns with
 * Newton iterative method.
 */

class NonLinearSystem : public NonLinearEquation{

public:

    /// Default constructor for a NonLinearSystem to solve with the Newton Iterative Method
    NonLinearSystem();
    /// Default destructor for a NonLinearSystem
    virtual ~NonLinearSystem();


    //Set Methods

    /// Method to set the starting point (x0,y0) of the Newton method.
    void SetStartingPoint(const double xn, const double yn);

    /// Method to set the two functions such that the system is : g(x,y)=0 and h(x,y)=0.
    void SetFunction(Function2D g_fun, Function2D h_fun);

    /** A method to solve a non-linear system with the newton iterative scheme:
    * \f$ z_(n+1)= z_n - J^{-1}(z_n) f(z_n) with z_n = (xn,yn) and f(z_n)=(g(zn),h(zn)) \f$
    */
    std::tuple<double, double> SolveSystem() ;

    double SolveEquation() override {throw std::runtime_error("The method SolveEquation cannot solve a NonLinearSytem \n"
                                                              "Try SolveSystem instead");};




protected:
    double x0;  ///< the initial point on x-axis
    double y0; ///< the initial point on y-axis
    Function2D g;  ///< the Function for the first equation
    Function2D h;  ///< the Function for the second equation




};


#endif //PCSC_PROJECT_NONLINEARSYSTEM_H
