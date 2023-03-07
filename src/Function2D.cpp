
#include "Function2D.h"
#include "Exceptions.h"

// Constructor and destructor
Function2D::Function2D(): fxy(0), dfx(0), dfy(0) {}   // throw error because cannot function cannot be null
Function2D::Function2D(std::function<double(double,double)> fun): fxy(fun), dfx(0), dfy(0) {}
Function2D::Function2D(std::function<double(double,double)> fun, std::function<double(double,double)> dfx_fun, std::function<double(double,double)> dfy_fun): fxy(fun) , dfx(dfx_fun),dfy(dfy_fun) {}
Function2D::~Function2D() {}

// Other public methods

// Value of the partial derivative along the first variable at point (d,e)
double Function2D::Prime_x(double d,double e) const {
    if (dfx == 0) {
        // calculate numerical derivative with central finite difference method
        double step_size = 0.000001;
        double forward_diff = (fxy(d+step_size,e)-fxy(d,e))/(step_size);
        double backward_diff = (fxy(d,e)-fxy(d-step_size,e))/(step_size);
        double central_diff = (fxy(d+step_size,e)-fxy(d-step_size,e))/(2*step_size);

        if (std::abs(forward_diff - backward_diff) > 0.1 || std::abs(forward_diff - central_diff) > 0.1 ||
            std::abs(backward_diff - central_diff) > 0.1) {
            std::cout << "WARNING: Function might not be continuous. " << std::endl;
        };

        return central_diff;
    } else {
        // calculate analytical derivative
        return dfx(d,e);
    }
}
// Value of the partial derivative along the second variable at point (d,e)
double Function2D::Prime_y(double d,double e) const {
    if (dfy == 0) {
        // calculate numerical derivative with central finite difference method
        double step_size = 0.000001;
        double forward_diff = (fxy(d,e+step_size)-fxy(d,e))/(step_size);
        double backward_diff = (fxy(d,e)-fxy(d,e-step_size))/(step_size);
        double central_diff = (fxy(d,e+step_size)-fxy(d,e-step_size))/(2*step_size);

        if (std::abs(forward_diff - backward_diff) > 0.1 || std::abs(forward_diff - central_diff) > 0.1 ||
            std::abs(backward_diff - central_diff) > 0.1) {
            std::cout << "WARNING: Function might not be continuous. " << std::endl;
        };

        return central_diff;
    } else {
        // calculate analytical derivative
        return dfy(d,e);
    }
}
// Value of the function at point (d,e)
double Function2D::CalculateValue(double d,double e) const {
    return fxy(d,e);
}

// Returns the function f
std::function<double(double,double)> Function2D::GetFunctionValue() const {
    return fxy;
}

// Returns the partial derivative df/dx
std::function<double(double,double)> Function2D::GetDerivative_x() const {

    if (dfx == 0) {
        // compute numerical derivative for any point with central finite difference method
        double step_size = 0.000001;
        return [=](double x,double y) {return (fxy(x+step_size,y) - fxy(x-step_size,y))/(2*step_size);};
    }

    return dfx;
}

// Returns the partial derivative df/dy
std::function<double(double,double)> Function2D::GetDerivative_y() const {

    if (dfy == 0) {
        // compute numerical derivative for any point with central finite difference method
        double step_size = 0.000001;
        return [=](double x,double y) {return (fxy(x,y+step_size) - fxy(x,y-step_size))/(2*step_size);};
    }

    return dfy;
}