
# PCSC Project, Non-Linear Systems

## Description
This is a program that implements numerical methods to solve a given nonlinear equation. Known mathematical methods (see [link](https://onlinelibrary.wiley.com/doi/pdf/10.1002/9781118673515.app8)) are implemented in C++ from a main class `NonLinearEquation`to solve an equation of the form f(x)=0. 

A separation is made with its two subclasses: 
- the `BisectionMethod` class uses the bisection procedure to find a solution in an interval [a,b] whose size is halfed at each step until only the value that is sought remains.
- the `IterativeMethod` class encompasses the chords, newton and fixed point methods. Basically, the algorithm searches the solution as limit of a suite (x~n~) such that x~n+1~ = x~n~ - g(x~n~) where g is a specific function for each method and x~0~ the starting point. 

A class `Function` is designed to create an object that facilitate the access to the mathematical application f and its derivative.  

Note that solving a Non-Linear System can also be done for a simple system of two equations and two unknowns, see in the corresponding section below.

## How to compile the program

The program will compile when opening Clion. The procedure in the next section will explain the program execution with the Clion interface.

Clion being based on a CMake system invoking the CMake executable with the appropriate parameters in the terminal is also possible. 

## Program execution for a regular equation

The program execution follow the steps of the flow diagram (see [link](https://gitlab.epfl.ch/naftalsk/pcsc_project/-/blob/master/FlowDiagram.PNG) or see the image FlowDiagram.PNG on the repository) for solving a non linear equation. The texts explain how to proceed when solving an equation in the main file of the program.

1/ Open the file `main.cpp` 

2/ Define the equation to be solved by creating a `Function` object from an `std::function`or a lambda function. This step can be done inside or outside the `int main()` of the file. 
(Optional: the analytical derivative of the application f can also be given to the `Function` constructor in order to have better results when calling iterative methods)
*
        double f(double x) {return ;}
        Function fun = Function(f);
 *
        std::function<double(double)> f = [](double x){return ;};
        Function fun = Function(f);

 * 
        Function fun = Function([](double x){return ;});

It is also possible to import from the hardcoded library by including the appropriate header file `.h` and then create the associated object:
*
      CosFunction Cos; 
*
      SinFunction Sin; 
*
      ExpFunction Exp; 
*
      LogFunction Log;

For a general equation of type u(x) = v(x), the `Function` to implement should be  f = u - v. Note that it is possible to create u and v independently and then implement their difference since the operators (+ , - , * , /) were overloaded to ensure that such simple combination is possible.

3/ The equation can now be solved using the following processes:
* Using `NonLinearSolver`:
    Within the main, calling `NonLinearSolver` allow to solve the equation. The solver takes as arguments the `Function` object defined at step 2, a `std::string` for the chosen method (either "Bisection", "FixedPoint", "Chords" or "Newton") , a `double` tol for the desired tolerance or precision on the solution and another `double` to set the maximum number of iterations. The last two arguments differs regarding the method:
 
    * The `BisectionMethod` needs the value of the first and second point forming the initial interval of research. They can be given in any order but need to be specified as a `double` even if the chosen number is an interger (ex: put `1.` instead of `1`) to avoid ambiguity.

            NonLinearSolver(fun, Method, tol, nb_it_max, first_point,second_point);

    * An `IterativeMethod` needs a `double` starting_point and a `bool` Aitken that should be set to `true` if the use of [Aitken acceleration method](https://en.wikipedia.org/wiki/Aitken%27s_delta-squared_process) is desired for the convergence of the suite.

            NonLinearSolver(fun, Method, tol, nb_it_max, starting_point, Aitken);

 
* Using a pointer
    The use of the pointers is simply doing manually what the `NonLinearSolver` does internally. 
    The initial step is to create the pointer with the associated method, and set the specific attributes for each daughter class.
    * If the bisection is selected, the specific attributes to be set is the value of the two end-points of interval [a,b]:
    
            BisectionMethod *pSolver;
            pSolver = new BisectionMethod;
            pSolver-> SetInterval(a,b)
    * If one of the iterative methods is selected, the specific attributes are the starting point x0 for the recurrence, the boolean for the use of the aitken acceleration and the iterative function that is used:
    
            IterativeMethod *pSolver;
            pSolver = new FixedPoint; //or new NewtonMethod, or new ChordsMethod
            pSolver->SetAitken(aitken); 
            pSolver->SetStartingPoint(x0);
            pSolver->SetIterativeFunction();
    
        Note that the SetIterativeFunction doesn't take arguments since the choice is implicitly made when a new method is assigned to the pointer. The set method here only enforce the choice. 

    The last lines for the solver are similar for the two cases since they depend on attributes inherited from the mother class `NonLinearEquation`. 
    
        pSolver->SetTolerance(tol);
        pSolver->SetMaxNumberIterations(nb_it_max);
        pSolver->SetFunction(fun);
        pSolver->SolveEquation();
        delete pSolver;
    The tolerance, the maximum number of iterations, and the `Function` needs to be set before calling the `SolveEquation()` method. In fact, all the preceding set methods can be put in an arbitrary order as long as solving the equation is called last. 

## System of equations (Optional part of project)
As of now, only a system of two equation can be solved. Such a system is simply refered to as an equation of the form f(x)=0 but with x a point of R^2^, and f an application of R^2^-> R^2^.

The class `NonLinearSystem` follows the newton method to find the zero of  f  by following the iterative scheme: 
z~n+1~= z~n~ - J^-1^(z~n~) f(z~n~) with z~n~ being a point of the plane R^2^ and J the jacobian of  f.

The class `Function2D` was created to represent an application with two variables, along with its two partial derivatives. As such the system is then represented by two `Function2D` g and h corresponding to the first and second component of f in the iterative scheme.

*   The flow is similar to the previous program execution but with subtle differences.
After opening the file `main.cpp`, the system to be solved needs to be defined by creating two `Function2D` object from an `std::function<double(double,double)>` or a lambda function. 
Optional: Similarly the two partial derivatives of the application can also be given to the constructor in order to have better results when calling a non linear system.

        Function2D fun1 = Function2D([](double x,double y){return ;});
        Function2D fun2 = Function2D([](double x,double y){return ;});
    The system can be solved in the same fashion as for a single equation:

    *  Using `NonLinearSolver`:
    Only the Newton method can be done by the `NonLinearSystem` therefore the type of method is not specicied, but two `Function2D` needs to be passed, followed by the tolerance and maximum number of iterations and finally the two double constituting the starting point (x~0~,y~0~):
    
            NonLinearSolver(fun1, fun2, tol, nb_it_max, x0, y0);

    *   With a pointer the procedure is the following. The set methods are essentially the same as for an iterative method but they only share the same name and doesn't take the same arguments, since a system needs two `Function2D`, and two `double` for the starting point. For the tolerance and the maximum iteration number they are inherited from the mother class. Finally, pay attention that the last method is `SolveSystem()` because the solution is a `tuple` and not a single `double`.
    Calling `SolveEquation()` on a `NonLinearSystem` throws an exception that recommends the user to use the adequate method.
    

            NonLinearSystem *pSolver;
            pSolver = new NonLinearSystem;
            pSolver->SetFunction(fun1,fun2);
            pSolver->SetStartingPoint(starting_point_x,starting_point_y);
            pSolver->SetTolerance(tolerance);
            pSolver->SetMaxNumberIterations(nb_max_iteration);
            pSolver-> SolveSystem();
            delete pSolver;
            
## List of features

* Storing the solution value inside a variable. 
* Displaying of the number of iterations taken to converge and satisfy the tolerance.
* A method `NonLinearSolver` that: 
    * allows to reduce the computation to a simple line of code
    * doesn't require the creation of a pointer solver
* Quick computation and accessibility of a derivative with `Function`.
* Access to a hardcoded library of `Function` object with set analytical derivatives.
* Combination between two `Function` with usual operators (+ , - , *, / , =). 

## List of tests

A file `Function_to_test.h` is created and imported in each file containing the tests to be run on the `NonLinearSolver`. Inside of it 10 functions with their roots being already known are implemented and the solution of the equation is checked for each of these functions, for the four types of methods (bisection, newton, fixed point). There are in total 4 files, one for each method with the general structure: 

    TEST(Method_test, Function_name) {   
        ASSERT_NEAR(root, NonLinearSolver(Function_name, Method, tol,nb_it_max,x,x),abs_error);
        ASSERT_THROW(root, NonLinearSolver(Function_name, Method, tol,nb_it_max,x,x),abs_error);
    }
The last two parameters being set according to used method as explained in the Program execution section. With these procedure the value returned for each method is checked along with the parameters that leds to the solver to diverge for the functions below:

*   A simple linear function:
    
        Function poly_deg1 = Function([](double x){return x + 4;});

    As this first function is linear, the 3 iterative methods (Fixed-point, Chords, Newton) will converge towards the root in one iteration, regardless of the starting point. 

* A polynomial of degree 2:

        Function poly_deg2 = Function([](double x){return x*x - x - 1;});
        
    Recall that to ensure global convergence in the interval (a, b) for a Fixed-point method, the derivative of the Phi function Phi(x) = x-f(x) must be strictly between -1 and 1 for all x in the interval. In our case, fixed-point has very little chance of working since abs(1-f'(x)) is greater than 1 for x between 0.5 and 1.5 However, Chords and Newton converge to the root which is closest to the starting point.

* A polynomial of degree 3:

        Function poly_deg3 = Function([](double x){return x*x*x -x + 9;});

    For the 3rd degree function the same phenomenon occurs for Fixed-point. For Chords and Newton one converges to the only solution if the starting point is sufficiently close to the root. 

* Two types of sum between a sinusoidal functions using the hardcoded with the harcoded and standard versions of sinus and cosinus:

        CosFunction cosine; SinFunction sine;
        Function sinusoid_harcoded = cosine + sine;
        Function sinusoid_standard = Function([](double x){return std::cos(x)+ std::sin(x);});

    For the sinusoid function the 3 iterative methods work well if the starting point is chosen correctly. Note that the solution is -pi/4 [pi] so we apply the remainder function (NonLinearSolver, pi) to the solution found with Newton to check the equality.

* An hyperbolic function

        Function hyperbolic = Function([](double x) {return std::cosh(x)-1;});

Similarly, the 3 functions converge if the starting point is close enough to 0. 

* Two types of sum between an exponential and a logarithmic function using their hardcoded and standard versions:
    
        ExpFunction Expo; LogFunction Log;
        Function exponential_hardcoded = Expo + Log;
        Function exponential_standard = Function([](double x) {
                                        return std::log(x) + std::exp(x);});

    Fixed-point never converges due to the too big slope and Chords/Newton converges as usual according to the starting point if one is close enough.  

* Finally two functions with a random combination of function from the standard library:
    
        Function fun_random = Function([](double x) {
                                return std::abs(cos(x)*cos(x) + 0.2*x*x*x);});
        Function fun_random2 = Function([](double x) {return std::abs(log(1+sin(x)));});

    These functions are complex and it is difficult to predict in advance whether a method will converge or not. In this case, the 3 methods converge if the starting point is well chosen. 

Note that we have not dealt with the bisection method since the method will always converge to a root (there can be more than one) if the function is continuous over the interval (a, b) and if f(a)f(b) is negative.


Other tests are conducted on the `Function` class in the file `Function_test.cpp` to check the operator overloads and the numerical derivation made by the class. In order: 

* For the addition  the following functions are compared with `sinusoid_harcoded` and `sinusoid_standard` defined in `Function_to_test.h`. 

        double sinusoid(double x) {return std::sin(x) + std::cos(x) ;}
        double d_sinusoid(double x) {return std::cos(x) - std::sin(x) ;}
    A loop on i going from 0 to 1000 is made and verifies that the value of `sinusoid` is equal to that of `sinusoid_harcoded.CalculateValue(x)` and `sinusoid_standard.CalculateValue(x)` where x = 2pi/1000, showing that the function are equals on one period 2pi.
    The same is done between `d_sinusoid` and the method `.Prime(x)` of the hardcoded and standard sinusoids which proves that both harcoded and numerical derivatives give correct results.

* For the multiplication the same process was done with the functions below in the interval [1,2]. 

        double exponential(double x) {return std::exp(x) * std::log(x) ;}
        double d_exponential(double x) {return std::exp(x) * std::log(x) + std::exp(x)/x ;}
        Function expo_log_hardcoded = Expo * Log;
        Function expo_log_standard = Function([](double x){return std::log(x)*std::exp(x);});

    The results are similar in the chosen range proving that the multiplication works correctly. It can be noted that the function has a particular pronounced asymptotical behaviour leading to some issues when testing outside this interval.
* The soustraction and multiplication are not checked because they are implemented from the two other operators which were tested.

## TODOs and perspectives

* Creating a mother class `SuperFunction`of `Function` and `Function2D` that will allow to create a function of n variables.
* Implementing a class `SuperFunctionVector` that will facilitate the representation of a Non-Linear system of n equations. 
* Implementing a class `SuperFunctionMatrix` that will facilitate the computation of the Jacobian and its inverse when using the Newton iterative scheme. 
* Accordingly the `NonLinearSystem` will be generalised and will have the vector as an attribute.
    * As of now it a subclass of `NonLinearEquation` that inherits the tolerance and iteration numbers arguments, but with a `SuperFunction` class it would be possible to have the new `NonLinearSystem` as the main class while the current `NonLinearSystem` will be named differently (ex:NonLinear2DSystem) and will be one of its subclasses along with `NonLinearEquation`.   



### Authors list

Authors: Jean Naftalski , Yannick Neypatraiky