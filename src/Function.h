
#ifndef PCSC_PROJECT_FUNCTION_H
#define PCSC_PROJECT_FUNCTION_H
#include <functional>
#include <iostream>

/**
 * This is a class to model a function and all the characteristics which are attached to it as its derivative.
 */

class Function {

public:

    /// Default constructor for a Function
    Function();
    /** \brief Construction of a Function from the mathematical expression of the function \f$ f \f$,
     *  without passing the expression of its derivative \f$ df \f$.
      *
      * As the analytical derivative function is unknown, methods that require the calculation of the
      * derivative \f$ df(x) \f$ will calculate a numerical derivative based on the central finite difference.
      */
    Function(std::function<double(double)> fun);
    /// Construction of a Function from the mathematical expression of the function \f$ f \f$,
    /// and the expression of its derivative \f$ df \f$.
    Function(std::function<double(double)> fun, std::function<double(double)> df_fun);
    /// Default destructor for a Function
    virtual ~Function();


    // Operators
    /// Overloading the = (assignment) operator for Functions
    Function &operator=(const Function &other_function);
    /// Overloading the unary - operator for Functions
    Function operator-() const;
    /// Overloading the binary + operator for Functions
    Function operator+(const Function &other_function) const;
    /// Overloading the binary - operator for Functions
    Function operator-(const Function &other_function) const;
    /// Overloading the unary * operator for Functions
    Function operator*(const double &d) const;   // be careful: it can be used only by writing f*cste, not cste*f
    /// Overloading the binary * operator for Functions
    Function operator*(const Function &other_function) const;
    /// Overloading the binary / operator for Functions
    Function operator/(const Function &other_function) const;


    // Other public methods

    /** \brief A virtual method to compute the derivative of \f$ f \f$ at point d.
     * \param Point d is a double.
     * \return Output a double which is the derivative at point d.
     *
     * This method is virtual because for some basic Functions (see daughter classes: sin, cos, etc) the analytical
     * derivatives are known. This Prime function will therefore evaluate the analytical derivative at
     * point d if the Function is a basic Function or a combination of basic Functions, or will calculate
     * the numerical derivative if the analytical derivative isn't known.
     */
    virtual double Prime(double d) const;
    /// Method to evaluate the Function \f$ f \f$ at point d.
    double CalculateValue(double d) const;


    /// Method to get the expression of \f$ f \f$.
    std::function<double(double)> GetFunctionValue() const;
    /** \brief A virtual method to compute the derivative function \f$ df \f$.
     * \return Output a std::function which is the derivative function.
     *
     * This method is similar to the Prime method but it returns a derivative function rather
     * than evaluating the derivative at one point.
     */
    std::function<double(double)> GetDerivative() const;

protected:
    std::function<double(double)> f;  ///< the analytical expression of the Function
    std::function<double(double)> df;   ///< the analytical expression of the derivative of the Function
};


#endif //PCSC_PROJECT_FUNCTION_H
