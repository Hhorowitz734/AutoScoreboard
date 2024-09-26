#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <sstream>
#include <iomanip>

typedef enum {
    LD,
    MULTD,
    SUBD,
    DIVD,
    ADDD
} INST;

typedef enum {
    F0,
    F1,
    F2, 
    F3,
    F4,
    F5,
    F6,
    F7, 
    F8, 
    F9,
    F10,

    R1,
    R2,
    R3,
    R4,
    R5
} Register;

typedef enum {
    NOT_STARTED,
    ISSUE,
    RO,
    EX,
    WR
} Status;

class Instruction {

public:

    // For anything except LD
    Instruction(INST instruction, Register destination, Register op1, Register op2)
        : instruction(instruction), destination(destination), op1(op1), op2(op2) {
            if (instruction == LD) { offset = -1; }
        };

    // For LD
    Instruction(INST instruction, Register destination, Register op1, size_t offset)
        : instruction(instruction), destination(destination), op1(op1), offset(offset) {};


    std::string inst_to_string() const {
        switch (instruction) {
            case LD:
                return "LD";
            case MULTD:
                return "MULTD";
            case SUBD:
                return "SUBD";
            case DIVD:
                return "DIVD";
            case ADDD:
                return "ADDD";
            default:
                return "Unknown Instruction";
        }
    }

    std::string register_to_string(Register reg) const {
        switch (reg) {
            case F0:
                return "F0";
            case F1:
                return "F1";
            case F2:
                return "F2";
            case F3:
                return "F3";
            case F4:
                return "F4";
            case F5:
                return "F5";
            case F6:
                return "F6";
            case F7:
                return "F7";
            case F8:
                return "F8";
            case F9:
                return "F9";
            case F10:
                return "F10";
            case R1: return "R1";
            case R2: return "R2";
            case R3: return "R3";
            case R4: return "R4";
            case R5: return "R5";
            default:
                return "Unknown Register";
        }
    }


    operator std::string() const {

        std::stringstream ss;

        ss << inst_to_string() << "\t";
        ss << register_to_string(destination) << ", ";

        // Handle LD
        if (instruction == LD) {
            ss << offset << "(" << register_to_string(op1) << ")";
            return ss.str();
        }

        ss << register_to_string(op1) << ", " << register_to_string(op2);

        return ss.str();
    }

private:

 
    // Instruction type
    INST instruction;

    // Instruction operands
    Register destination;
    Register op1;
    Register op2;
    size_t offset; // For LD

    // Status
    Status status = NOT_STARTED;
};

#endif