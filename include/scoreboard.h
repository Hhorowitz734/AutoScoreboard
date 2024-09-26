#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "instruction.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>

class Scoreboard {

public:

    void push(Instruction instruction) { instruction_q.push_back(instruction); }

    std::string q_to_string() {

        if (instruction_q.empty()) { return "Instruction queue is empty."; }
        
        std::stringstream ss;

        for (Instruction inst : instruction_q) {
            ss << std::string(inst) << "\n";
        }

        return ss.str();

    }

private:

    std::vector<Instruction> instruction_q;

};


#endif