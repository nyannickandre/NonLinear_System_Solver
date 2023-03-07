
#ifndef PCSC_PROJECT_NONLINEARSOLVER_H
#define PCSC_PROJECT_NONLINEARSOLVER_H

#include <iostream>
#include "NonLinearEquation.h"
#include "Function.h"
#include "BisectionMethod.h"
#include "IterativeMethod.h"
#include "FixedPoint.h"
#include "NewtonMethod.h"
#include "ChordsMethod.h"
#include "NonLinearSystem.h"

/** \brief General function to solve the non-linear equation with Bisection.
  * \param the non-linear Function fun.
  * \param the Method which will be used (std::string).
  * \param the tolerance tol define the precision of the solution.
  * \param the maximum number of iterations nb_max_iteration.
  * \param the lower bound of the interval first_point.
  * \param the upper bound of the interval second_point.
  * \return return a double which is a root of the equation.
  */
double NonLinearSolver(Function fun, std::string Method, double tolerance, int nb_max_iteration,double first_point = 0, double second_point = 0){

    if(Method=="Bisection"){
        BisectionMethod *pSolver = nullptr;
        pSolver = new BisectionMethod;
        pSolver->SetFunction(fun);
        pSolver->SetInterval(first_point,second_point);
        pSolver->SetTolerance(tolerance);
        pSolver->SetMaxNumberIterations(nb_max_iteration);
        double ans = pSolver-> SolveEquation();
        delete pSolver;
    return ans;
    }

}


/** \brief General function to solve the non-linear equation with one of the iterative methods.
  * \param the non-linear Function fun.
  * \param the Method which will be used (std::string).
  * \param the tolerance tol define the precision of the solution.
  * \param the maximum number of iterations nb_max_iteration.
  * \param the starting point starting_point.
  * \param the boolean for Aitken
  * \return return a double which is a root of the equation.
  */
double NonLinearSolver(Function &fun, std::string Method, double tolerance, int nb_max_iteration, double starting_point = 0, bool Aitken = false){

    IterativeMethod *pSolver;
    if(Method=="Newton")
        {pSolver = new NewtonMethod;}
    else if(Method=="Chords")
        {pSolver = new ChordsMethod;}
    else if
        (Method=="FixedPoint"){pSolver = new FixedPoint;}
    else
        {throw std::not_implemented_method("There is no method called " + Method + ". " );}
    pSolver->SetFunction(fun);
    pSolver->SetTolerance(tolerance);
    pSolver->SetMaxNumberIterations(nb_max_iteration);
    pSolver->SetStartingPoint(starting_point);
    pSolver->SetIterativeFunction();
    pSolver->SetAitken(Aitken);
    double ans = pSolver-> SolveEquation();
    delete pSolver;
    return ans;
}

std::tuple<double, double> NonLinearSolver(Function2D &fun1, Function2D &fun2, double tolerance, int nb_max_iteration, double starting_point_x, double starting_point_y){

    NonLinearSystem *pSolver;
    pSolver = new NonLinearSystem;

    pSolver->SetFunction(fun1,fun2);
    pSolver->SetTolerance(tolerance);
    pSolver->SetMaxNumberIterations(nb_max_iteration);
    pSolver->SetStartingPoint(starting_point_x,starting_point_y);
    std::tuple<double, double> ans = pSolver-> SolveSystem();
    delete pSolver;
    return ans;
}

#endif //PCSC_PROJECT_NONLINEARSOLVER_H

