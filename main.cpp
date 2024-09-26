#include "include/scoreboard.h"


int main() {
    
    Scoreboard scoreboard;

    Instruction load_1(LD, F6, R2, 34);
    Instruction load_2(LD, F2, R3, 45);
    Instruction mult(MULTD, F0, F6, F2);
    Instruction subd(SUBD, F8, F6, F2);
    Instruction divd(DIVD, F10, F0, F6);
    Instruction addd(ADDD, F6, F8, F2);

    std::cout << scoreboard.q_to_string() << std::endl;

    scoreboard.push(load_1);
    scoreboard.push(load_2);
    scoreboard.push(mult);
    scoreboard.push(subd);
    scoreboard.push(divd);
    scoreboard.push(addd);
    
    std::cout << scoreboard.q_to_string() << std::endl;

    return 0;
}
