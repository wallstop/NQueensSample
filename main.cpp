
#include <iostream>
#include "VTimer.h"
#include "NQueens.h"

int main(int argc, char* argv[])
{
    static const int ITERATIONS = 12;
    VTimer timer;
    timer.setStartTick();
    nQueens(ITERATIONS);
    double now = timer.time_u();

    std::cout << "Sequential NQueens of     " << ITERATIONS << " took: " << now << "\t nanoseconds." << std::endl;

    timer.setStartTick();
    semiParallelNQueens(ITERATIONS);
    now = timer.time_u();
    std::cout << "Badly parallel NQueens of " << ITERATIONS << " took: " << now << "\t nanoseconds." << std::endl;

    std::cin.get();

}