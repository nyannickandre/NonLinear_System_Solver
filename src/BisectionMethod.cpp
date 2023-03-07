
#include "BisectionMethod.h"
#include <iostream>

BisectionMethod::BisectionMethod(): x(),y() {}

BisectionMethod::~BisectionMethod() {}


void BisectionMethod::SetInterval(double a, double b) { if(a<b){x=a;y=b;}else{y=a;x=b;} }

double BisectionMethod::SolveEquation() {
    double a = x;
    double b = y;
    double c = (a+b)/2 ;
    double nb_it = 0;

    if(f.CalculateValue(a)*f.CalculateValue(b) > 0 ) {
        throw std::domain_error( "There is no solution in the interval [" + std::to_string(a) + ", " + std::to_string(b) + " ]" );
    }
    else{
        while( std::abs(b - c) > tol && nb_it < n_max){
            if(f.CalculateValue(b)*f.CalculateValue(c) <= 0){
                a = c;
            }
            else{b = c;}
            nb_it = nb_it + 1;
            c = (a+b)/2;

        }

    }

    if ( (std::abs(b - c) > tol) || isnan(c) || isnan(f.CalculateValue(c)) ) {
        throw std::convergence_error("Bisection stopped without converging to the desired convergence"
                                     " because the maximum number of iterations was reached.");
    }

    std::cout << "Bisection converges in " << nb_it << " iterations to " << c << " in the interval " << "[" << x << "," << y <<"]."
              << "\n" << std::endl;

    return c;

}
