/*
    C++ port of https://github.com/reem/rust-n-queens
*/

#pragma once

#include <vector>
#include <future>

static inline int getValidPositions(int allOnes, int leftDiagonals, int columns, int rightDiagonals)
{
    return (~(leftDiagonals | columns | rightDiagonals)) & allOnes;
}

static inline int getLSB(int validPositions)
{
    return ((-validPositions) & validPositions);
}

static inline int getNumBits(int validPositions)
{
    int ret = 0;
    for(; validPositions != 0; ++ret)
        validPositions &= (validPositions - 1);

    return ret;
}

static unsigned int nQueensHelper(int allOnes, int leftDiagonals, int columns, int rightDiagonals)
{
    unsigned int solutions = 0;
    int validPositions = getValidPositions(allOnes, leftDiagonals, columns, rightDiagonals);

    while(validPositions != 0)
    {
        const int position = getLSB(validPositions);
        validPositions ^= position;
        solutions += nQueensHelper(allOnes, (leftDiagonals | position) << 1, (columns | position), (rightDiagonals | position) >> 1);
    }

    return solutions + ((columns == allOnes) ? 1 : 0);
}

static unsigned int semiParallelNQueens(int n)
{
    const int allOnes = (1 << n) - 1;
    const int columns = 0;
    const int leftDiagonals = 0;
    const int rightDiagonals = 0;

    int validPositions = getValidPositions(allOnes, leftDiagonals, columns, rightDiagonals);

    /*
        This all super sucks, if this were an actual implementation I'd rely on TBB's nice parallel paradigms
        and thread pools and stuff 
    */
    unsigned int result = 0;
    std::vector<std::future<unsigned int>> threadPool;
    while(validPositions != 0)
    {
        std::packaged_task<unsigned int(int, int, int, int)> task(nQueensHelper);
        const int position = getLSB(validPositions);
        validPositions ^= position;
        threadPool.push_back(task.get_future());
        task(allOnes, (leftDiagonals | position) << 1, (columns | position), (rightDiagonals | position) >> 1);
    }

    // Here would be a nice place for a parallel summation, would have to make result atomic
    for(auto& thread : threadPool)
        result += thread.get();

    return result + ((columns == allOnes) ? 1 : 0);
}

static inline unsigned int nQueens(int n)
{
    return nQueensHelper((1 << n) - 1, 0, 0, 0);
}
