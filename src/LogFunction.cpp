
#include "LogFunction.h"

// Constructor and destructor
LogFunction::LogFunction() {
    f = [](double x){return log(x);};
    df = [](double x){return 1/x;};
}
LogFunction::~LogFunction() {}


// Other public methods
double LogFunction::Prime(double d) const {
    return df(d);
}