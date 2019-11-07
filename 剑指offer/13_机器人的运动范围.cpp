#include <iostream>
#include <string.h>
class Solution {
public:
    bool check(int threshold, int row, int col)
    {
        int sum = 0;
        while(row)
        {
            sum += (row % 10);
            row /= 10;
        }
        while(col)
        {
            sum += (col % 10);
            col /= 10;
        }
        if(sum <= threshold)
        {
            return true;
        }
        return false;
    }
    void movingCountCore(int threshold, int rows, int cols, int row, int col, int* count, bool* isTrace)
    {
        
        if(row >= 0 && row < rows && col >= 0 && col < cols && (isTrace[row * cols + col] == false) && check(threshold, row, col))
        {
            (*count)++;
            isTrace[row * cols + col] = true;
            movingCountCore(threshold, rows, cols, row + 1, col, count, isTrace);
            movingCountCore(threshold, rows, cols, row, col + 1, count, isTrace);
            movingCountCore(threshold, rows, cols, row - 1, col, count, isTrace);
            movingCountCore(threshold, rows, cols, row, col - 1, count, isTrace);
        }
    }
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold < 0 || rows <= 0 || cols <= 0)
        {
            return 0;
        }
        bool* isTrace = new bool[rows * cols];
        memset(isTrace, false, rows * cols * sizeof(bool));
        int count = 0;
        movingCountCore(threshold, rows, cols, 0, 0, &count, isTrace);
        delete[] isTrace;
        return count;
    }
};