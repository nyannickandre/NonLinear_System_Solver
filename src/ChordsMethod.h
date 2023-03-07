
#ifndef PCSC_PROJECT_CHORDSMETHOD_H
#define PCSC_PROJECT_CHORDSMETHOD_H
#include "IterativeMethod.h"

/**
* This class implements the Chords method.
*/


class ChordsMethod: public IterativeMethod {
public:

    /// Default constructor for a Chords method
    ChordsMethod();
    /// Default destructor for a Chords method
    virtual ~ChordsMethod();


    /// Method to set the iterative function as \f$ g(x)=\frac{f(x)}{df(x0)} \f$.
    void SetIterativeFunction() override;

};


#endif //PCSC_PROJECT_CHORDSMETHOD_H
