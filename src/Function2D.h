
#ifndef PCSC_PROJECT_FUNCTION2D_H
#define PCSC_PROJECT_FUNCTION2D_H

#include <functional>
#include <iostream>

/**
 * This is a class to model a function of two variables and all the characteristics which are attached to it as
 * its partial derivatives.
 */

class Function2D {

public:

    /// Default constructor for a Function2D
    Function2D();
    /** \brief Construction of a Function2D from the mathematical expression of the function \f$ f \f$,
     *  without passing the expression of its partial derivatives \f$ df/dx \f$ and \f$ df/dy \f$.
      *
      * As the analytical derivatives functions are unknown, methods that require the calculation of the
      * derivative \f$ df(x,y)/dx \f$ and \f$ df(x,y)/dy \f$ will calculate a numerical derivative based on the central finite difference.
      */
    Function2D(std::function<double(double,double)> fun);
    /// Construction of a Function2D from the mathematical expression of the function \f$ f \f$,
    /// and the expression of its derivative \f$ df/dx \f$ and \f$ df/dy \f$.
    Function2D(std::function<double(double,double)> fun, std::function<double(double,double)> dfx_fun, std::function<double(double,double)> dfy_fun);
    /// Default destructor for a Function
    virtual ~Function2D();

    // Other public methods

    /** \brief Virtual method to compute the partial derivatives of \f$ f \f$ at point d.
     * \param Point d and e are doubles.
     * \return Output a double which is the partial derivative at point (d,e).
     *
     * This method is virtual because for some basic Functions (see daughter classes: sin, cos, etc) the analytical
     * derivatives are known. This Prime_x and Prime_y function will therefore evaluate the analytical derivative at
     * point d if the Function is a basic Function or a combination of basic Functions, or will calculate
     * the numerical derivative if the analytical derivative isn't known.
     */
    virtual double Prime_x(double d,double e) const;
    virtual double Prime_y(double d,double e) const;
    /// Method to evaluate the Function \f$ f \f$ at point (d,e).
    double CalculateValue(double d, double e) const;


    /// Method to get the expression of \f$ f \f$.
    std::function<double(double,double)> GetFunctionValue() const;
    /** \brief Virtual methods to compute the partial derivative functions \f$ df/dx \f$ and \f$ df/dy \f$.
     * \return Output the std::function which are the partial derivative function.
     *
     * This method is similar to the Prime_x and Prime_y method but it returns the derivative function rather
     * than evaluating the derivative at one point.
     */
    std::function<double(double,double)> GetDerivative_x() const;
    std::function<double(double,double)> GetDerivative_y() const;


protected:
    std::function<double(double,double)> fxy;  ///< the analytical expression of the Function2D
    std::function<double(double,double)> dfx;   ///< the analytical expression of the partial derivative of the Function along the first variable
    std::function<double(double,double)> dfy;   ///< the analytical expression of the partial derivative of the Function along the second variable
};


#endif //PCSC_PROJECT_FUNCTION2D_H
