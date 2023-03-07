
#ifndef PCSC_PROJECT_EXCEPTIONS_H
#define PCSC_PROJECT_EXCEPTIONS_H

#include <stdexcept>
#include <string>

namespace std {

/**
* This class is the a derived class of runtime_error.  It allows to stop the program and display an error message if
* the method is not converging, rather than displaying an erroneous response.
*/
class convergence_error : public runtime_error { using runtime_error::runtime_error; };

/**
* This class is the a derived class of runtime_error.  It allows to stop the program and display an error message if
* the method is not implemented.
*/
class not_implemented_method : public runtime_error { using runtime_error::runtime_error; };

}

#endif //PCSC_PROJECT_EXCEPTIONS_H
