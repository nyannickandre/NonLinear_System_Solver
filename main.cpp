#include <iostream>
#include "src/NonLinearEquation.h"
#include "src/Function.h"
#include "src/BisectionMethod.h"
#include "src/IterativeMethod.h"
#include <cmath>
#include <functional>
#include "src/CosFunction.h"
#include "src/SinFunction.h"
#include "src/ExpFunction.h"
#include "src/LogFunction.h"
#include "src/FixedPoint.h"
#include "src/NewtonMethod.h"
#include "src/ChordsMethod.h"
#include "src/NonLinearSolver.h"
#include "src/Function2D.h"


// Define the function (Optional: the analytical derivative can be passed as an argument)
Function fun = Function([](double x){return x;});


 int main() {
    int NonLinearSolver(fun,"Newton",0.000001,1000,2.,true);

    return 0;
}
