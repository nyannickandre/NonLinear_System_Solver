
#include "CosFunction.h"

// Constructor and destructor
CosFunction::CosFunction() {
    f = [](double x){return cos(x);};
    df = [](double x){return -sin(x);};
}
CosFunction::~CosFunction() {}


// Other public methods
double CosFunction::Prime(double d) const {
        return df(d);
    }