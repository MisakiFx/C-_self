#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        // write code here
        vector<int> value(6, 0);
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                int left = 0;
                int up = 0;
                if(i > 0)
                {
                    up = value[j];
                }
                if(j > 0)
                {
                    left = value[j - 1];
                }
                value[j] = max(up, left) + board[i][j];
            }
        }
        return value[5];
    }
};