
#include "NonLinearSystem.h"
#include <iostream>


// Default constructor for a NonLinearSystem to solve with the Newton Iterative Method
NonLinearSystem::NonLinearSystem(): x0(),y0(),g(),h() {}

// Default destructor for a NonLinearSystem
NonLinearSystem::~NonLinearSystem(){}


//Set Methods

// Method to set the starting point x0 of the iterative method.
void NonLinearSystem::SetStartingPoint(const double xn, const double yn){
    x0=xn; y0 = yn;
}

// Method to set the two functions such that the system is : g(x,y)=0 and h(x,y)=0.
void NonLinearSystem::SetFunction(Function2D g_fun, Function2D h_fun){
    g = g_fun; h = h_fun;
}

// A method to solve a non-linear system with the newton iterative scheme:
// z_(n+1)= z_n - J^{-1}(z_n) f(z_n) with z_n = (xn,yn) and f(z_n)=(g(zn),h(zn))

std::tuple<double, double> NonLinearSystem::SolveSystem() {
    double xn = x0;
    double yn = y0;
    int nb_it = 0;

    //Define double which values will be overwritten at each iteration to store the values of the function and their partial
    //derivatives at current point (xn,yn)
    double detJ_inv = 0; // will store the inverse of the determinant of the Jacobian
    double gn = 0; //will store the value g(xn,yn)
    double hn = 0; //will store the value g(xn,yn)
    double dgx = 0; //will store the value dg/dx(xn,yn)
    double dgy = 0; //will store the value dg/dy(xn,yn)
    double dhx = 0; //will store the value dh/dx(xn,yn)
    double dhy = 0; //will store the value dh/dy(xn,yn)


    while( std::abs(g.CalculateValue(xn,yn)) > tol || std::abs(h.CalculateValue(xn,yn)) > tol && nb_it < n_max ) {
        //Use of Prime_x and Prime_y to compute the coefficient of the Jacobian J(xn,yn)
        dgx = g.Prime_x(xn,yn);
        dgy = g.Prime_y(xn,yn);
        dhx = h.Prime_x(xn,yn);
        dhy = h.Prime_y(xn,yn);

        //The inverse of the determinant of J(xn,yn)
        detJ_inv = 1/(dgx*dhy - dhx*dgy);

        //The two functions corresponding to the two lines of f(xn,yn)
        gn = g.CalculateValue(xn,yn);
        hn = h.CalculateValue(xn,yn);

        // Calculating z_(n+1) with the scheme of the Newton method
        xn = xn - detJ_inv*(dhy*gn - dgy*hn);
        yn = yn - detJ_inv*(dgx*hn-dhx*gn);

        nb_it = nb_it + 1;
    }

    if ( std::abs(g.CalculateValue(xn,yn)) > tol || std::abs(h.CalculateValue(xn,yn )) > tol ) {
        throw std::convergence_error("Newton method stopped without converging to the desired convergence \n "
                                     "Try another initial point.");
    }

    if (isnan(g.CalculateValue(xn,yn)) || isnan(h.CalculateValue(xn,yn)) || isnan(xn) || isnan(yn)) {
        throw std::convergence_error("Newton method stopped without converging to the desired convergence \n "
                                     "Try another initial point.");
    }

    std::cout << "Newton method converges in " << nb_it << " iterations to (" << xn << "," << yn << ")" << "\n" << std::endl;


    return std::make_tuple(xn,yn);
}