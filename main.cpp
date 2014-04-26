
#include <iostream>
#include "VTimer.h"
#include "NQueens.h"

int main(int argc, char* argv[])
{
    static const int ITERATIONS = 12;
    VTimer timer;
    timer.setStartTick();
    const unsigned int seqResult = nQueens(ITERATIONS);
    double now = timer.time_u();

    std::cout << "Sequential NQueens of     " << ITERATIONS << " took: " << now << "\t microseconds." << std::endl;

    timer.setStartTick();
    const unsigned int parallelResult = semiParallelNQueens(ITERATIONS);
    now = timer.time_u();
    std::cout << "Badly parallel NQueens of " << ITERATIONS << " took: " << now << "\t microseconds." << std::endl;

    if(parallelResult == seqResult)
        std::cout << "Sequential and parallel results are the same" << std::endl;
    else
        std::cout << "Sequential and parallel results are NOT the same. THIS IS BAD." << std::endl;

    std::cin.get();

}