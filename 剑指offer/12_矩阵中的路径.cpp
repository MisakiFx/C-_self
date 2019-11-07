#include <iostream>
#include <string.h>
class Solution {
public:
    bool hasPathCore(char* matrix, int rows, int cols, char* str, int pathLength, int row, int col, bool* isTrace)
    {
        if(pathLength == strlen(str))
        {
            return true;
        }
        bool hasPath = false;
        if(row < rows && col < cols && row >= 0 && col >= 0 
          && matrix[row * cols + col] == str[pathLength]
          && isTrace[row * cols + col] == false)
        {
            pathLength++;
            isTrace[row * cols + col] = true;
            //向四周递归
            if(hasPathCore(matrix, rows, cols, str, pathLength, row + 1, col, isTrace)
              || hasPathCore(matrix, rows, cols, str, pathLength, row, col + 1, isTrace)
              || hasPathCore(matrix, rows, cols, str, pathLength, row - 1, col, isTrace)
              || hasPathCore(matrix, rows, cols, str, pathLength, row, col - 1, isTrace))
            {
                hasPath = true;
            }
            if(hasPath == false)
            {
                pathLength--;
                isTrace[row * cols + col] = false;
            }
        }
        return hasPath;
    }
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        bool* isTrace = new bool[rows * cols];
        memset(isTrace, false, (rows * cols) * sizeof(bool));
        int pathLength = 0;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(hasPathCore(matrix, rows, cols, str, pathLength, i, j, isTrace))
                {
                    delete[] isTrace;
                    return true;
                }
            }
        }
        delete[] isTrace;
        return false;
    }
};