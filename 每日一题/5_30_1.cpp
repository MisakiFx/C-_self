//井字棋判断获胜
#include <iostream>
#include <vector>
using namespace std;
class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here
        for(int i = 0; i < 3; i++)
        {
            int sum = board[0][i] + board[1][i]+ board[2][i];
            if(sum == 3)
            {
                return true;
            }
        }
         for(int i = 0; i < 3; i++)
        {
            int sum = board[i][0] + board[i][1]+ board[i][2];
            if(sum == 3)
            {
                return true;
            }
        }
        int sum = board[0][0] + board[1][1] + board[2][2];
        if(sum == 3)
        {
            return true;
        }
        sum = board[0][2] + board[1][1] + board[2][0];
        if(sum == 3)
        {
            return true;
        }
        return false;
    }
};