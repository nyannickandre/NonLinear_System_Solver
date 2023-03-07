
#include "SinFunction.h"

// Constructor and destructor
SinFunction::SinFunction() {
    f = [](double x){return sin(x);};
    df = [](double x){return cos(x);};
}
SinFunction::~SinFunction() {}


// Other public methods
double SinFunction::Prime(double d) const {
    return df(d);
}