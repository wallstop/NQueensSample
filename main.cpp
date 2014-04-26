
#include <iostream>
#include "VTimer.h"
#include "NQueens.h"

int main(int argc, char* argv[])
{
    static const int BOARD_SPACE = 12;
    VTimer timer;
    timer.setStartTick();
    const unsigned int seqResult = nQueens(BOARD_SPACE);
    double now = timer.time_u();

    std::cout << "Sequential NQueens of     " << BOARD_SPACE << " took: " << now << "\t microseconds." << std::endl;

    timer.setStartTick();
    const unsigned int parallelResult = semiParallelNQueens(BOARD_SPACE);
    now = timer.time_u();
    std::cout << "Badly parallel NQueens of " << BOARD_SPACE << " took: " << now << "\t microseconds." << std::endl;

    if(parallelResult == seqResult)
        std::cout << "Sequential and parallel results are the same : " << parallelResult << std::endl;
    else
        std::cout << "Sequential and parallel results are NOT the same( " << 
            seqResult << " " << parallelResult << " ). THIS IS BAD." << std::endl;
}