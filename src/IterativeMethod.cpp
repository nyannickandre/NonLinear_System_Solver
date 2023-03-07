
#include "IterativeMethod.h"
#include <iostream>
#include <deque>


// Constructor and destructor
IterativeMethod::IterativeMethod(): g(), Aitken(), x0(){}

IterativeMethod::~IterativeMethod() {}

// Set methods
void IterativeMethod::SetStartingPoint(const double xn) { x0 = xn; }
void IterativeMethod::SetAitken(const bool AitkenAcceleration) { Aitken = AitkenAcceleration; }

double IterativeMethod::SolveEquation(){
      double xn = x0;
      int nb_it = 0;

      // Declaration of elements that will be used for the Aitken acceleration
      std::deque<double> p_queue;
      p_queue.push_back(xn);
      double lambda = 0;
      double estimator = 0;

      while( std::abs(f.CalculateValue(xn)) > tol && nb_it < n_max ) {
          xn = xn - g.CalculateValue(xn);
          if(Aitken){
              p_queue.push_back(xn);
              if(p_queue.size()==3){
                  lambda = (p_queue[2] - p_queue[1])/(p_queue[1] - p_queue[0]);
                  estimator = (lambda/(1-lambda))*(p_queue[2]-p_queue[1]);
                  xn = xn + estimator;
                  p_queue.pop_front();
              }

          }
          nb_it = nb_it + 1;
      }

      if ( std::abs(f.CalculateValue(xn) ) > tol || isnan(xn) || isnan(f.CalculateValue(xn)) ){
          throw std::convergence_error("Iterative method stopped without converging to the desired convergence. \n"
                                     "Try another initial point.");
      }

      std::cout << "Iterative method converges in " << nb_it << " iterations to " << xn << "\n" << std::endl;


      return xn;
}
