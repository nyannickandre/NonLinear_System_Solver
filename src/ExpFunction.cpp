
#include "ExpFunction.h"

// Constructor and destructor
ExpFunction::ExpFunction() {
    f = [](double x){return exp(x);};
    df = [](double x){return exp(x);};
}
ExpFunction::~ExpFunction() {}


// Other public methods
double ExpFunction::Prime(double d) const {
    return df(d);
}