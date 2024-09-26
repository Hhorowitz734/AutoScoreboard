#ifndef CPU_H
#define CPU_H

#include "scoreboard.h"
#include "functional_unit.h"
#include <memory>

class CPU {

public:

    CPU() {
        // Instantiate scoreboard
        scoreboard = std::make_unique<Scoreboard>();

        // Instantiate FUs
        integer = std::make_unique<FunctionalUnit>(Integer);
        mult1 = std::make_unique<FunctionalUnit>(Mult);
        mult2 = std::make_unique<FunctionalUnit>(Mult);
        add = std::make_unique<FunctionalUnit>(Add);
        divide = std::make_unique<FunctionalUnit>(Divide);
    }

    void push_instruction(Instruction instruction) {
        scoreboard->push(instruction);
        // Maybe instruction should pass by value
        // Figure this out later
        
    }

private:

    std::unique_ptr<Scoreboard> scoreboard;

    std::unique_ptr<FunctionalUnit> integer;
    std::unique_ptr<FunctionalUnit> mult1;
    std::unique_ptr<FunctionalUnit> mult2;
    std::unique_ptr<FunctionalUnit> add;
    std::unique_ptr<FunctionalUnit> divide;


};



#endif