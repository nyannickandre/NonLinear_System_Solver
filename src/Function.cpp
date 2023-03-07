
#include "Function.h"
#include "Exceptions.h"

// Constructor and destructor
Function::Function(): f(0), df(0) {}   // throw error because cannot function cannot be null
Function::Function(std::function<double(double)> fun): f(fun), df(0) {}
Function::Function(std::function<double(double)> fun , std::function<double(double)> df_fun): f(fun), df(df_fun) {}
Function::~Function() {}


// Operators
// Overloading the = (assignment) operator
Function &Function::operator=(const Function &other_function) {
    f = other_function.f;
    df = other_function.df;
    return *this;
}


// Overloading the unary - operator
Function Function::operator-() const {
    Function fun;
    fun.f = [=](double x) {return -f(x);};
    fun.df = [=](double x) {return -df(x);};
    return fun;
}


// Overloading the binary + operator
Function Function::operator+(const Function &other_function) const{
    Function fun;
    fun.f = [=](double x) {return f(x) + other_function.f(x);};
    fun.df = [=](double x) {return df(x) + other_function.df(x);};
    return fun;
}


// Overloading the binary - operator
Function Function::operator-(const Function &other_function) const {
    Function fun;
    fun.f = [=](double x) {return f(x) - other_function.f(x);};
    fun.df = [=](double x) {return df(x) - other_function.df(x);};
    return fun;
}


// Overloading the unary * operator
Function Function::operator*(const double &d) const {
    Function fun;
    fun.f = [=](double x) {return d * f(x);};
    fun.df = [=](double x) {return d * df(x);};
    return fun;
}


// Overloading the binary * operator
Function Function::operator*(const Function &other_function) const {
    Function fun;
    fun.f = [=](double x) {return f(x) * other_function.f(x);};
    fun.df = [=](double x) {return df(x) * other_function.f(x) + f(x) * other_function.df(x);};
    return fun;
}


// Overloading the binary / operator
Function Function::operator/(const Function &other_function) const {
    Function fun;
    fun.f = [=](double x) {return f(x) / other_function.f(x);};
    fun.df = [=](double x) {return (df(x) * other_function.f(x) - f(x) * other_function.df(x)) /
                            (other_function.f(x) * other_function.f(x));};
    return fun;
}



// Other public methods
double Function::Prime(double d) const {
    if (df == 0) {
        // calculate numerical derivative with central finite difference method
        double step_size = 0.000001;
        double forward_diff = (f(d+step_size)-f(d))/(step_size);
        double backward_diff = (f(d)-f(d-step_size))/(step_size);
        double central_diff = (f(d+step_size)-f(d-step_size))/(2*step_size);

        if (std::abs(forward_diff - backward_diff) > 0.1 || std::abs(forward_diff - central_diff) > 0.1 ||
            std::abs(backward_diff - central_diff) > 0.1) {
            std::cout << "WARNING: Function might not be continuous. " << std::endl;
        };

        return central_diff;
    } else {
        // calculate analytical derivative
        return df(d);
    }
}

double Function::CalculateValue(double d) const {
        return f(d);
}



std::function<double(double)> Function::GetFunctionValue() const {
    return f;
}


std::function<double(double)> Function::GetDerivative() const {

    if (df == 0) {
    // compute numerical derivative for any point with central finite difference method
        double step_size = 0.000001;
        return [=](double x) {return (f(x+step_size) - f(x-step_size))/(2*step_size);};
    }

    return df;
}
