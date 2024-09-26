#ifndef FUNCTIONAL_UNIT_H
#define FUNCTIONAL_UNIT_H

#include "instruction.h"

typedef enum {
    Integer,
    Mult,
    Add,
    Divide
} UNIT_TYPE;

class FunctionalUnit {
public:

    FunctionalUnit(UNIT_TYPE function) 
        : type(function) {};

private:

    bool isBusy;

    UNIT_TYPE type;
    
};

#endif