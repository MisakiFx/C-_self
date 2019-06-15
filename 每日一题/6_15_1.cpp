#include <iostream>
#include <vector>
using namespace std;
class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        // write code here
        vector<vector<int>> price(6, vector<int>(6, 0));
        price[0][0] = board[0][0];
        for(int i = 1; i < 6; i++)
        {
            price[0][i] = price[0][i - 1] + board[0][i];
        }
        for(int i = 1; i < 6; i++)
        {
            price[i][0] = price[i - 1][0] + board[i][0];
        }
        for(int i = 1; i < 6; i++)
        {
            for(int j = 1; j < 6; j++)
            {
                int num1 = price[i - 1][j] + board[i][j];
                int num2 = price[i][j - 1] + board[i][j];
                price[i][j] = max(num1, num2);
            }
        }
        return price[5][5];
    }
};