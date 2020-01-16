#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void PrintOnce(vector<vector<int>>& matrix, vector<int>& res, int start)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int endX = col - start - 1;
        int endY = row - start - 1;
        for(int i = start; i <= endX; i++)
        {
            res.push_back(matrix[start][i]);
        }
        if(start < endY)
        {
            for(int i = start + 1; i <= endY; i++)
            {
                res.push_back(matrix[i][endX]);
            }
        }
        if(start < endY && start < endX)
        {
            for(int i = endX - 1; i >= start; i--)
            {
                res.push_back(matrix[endY][i]);
            }
        }
        if(start < endX && start < endY - 1)
        {
            for(int i = endY - 1; i > start; i--)
            {
                res.push_back(matrix[i][start]);
            }
        }
    }
    vector<int> printMatrix(vector<vector<int>> matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res;
        int start = 0;
        while(start * 2 < row && start * 2 < col)
        {
            PrintOnce(matrix, res, start);
            start++;
        }
        return res;
    }
};
