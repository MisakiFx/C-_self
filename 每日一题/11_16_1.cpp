#include <iostream>
#include <vector>
using namespace std;
class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == 1)
                {
                    
                    int count = 0;
                    int tempj = j;
                    int tempi = i;
                    while(tempj < board[0].size() && board[tempi][tempj] == 1)
                    {
                        count++;
                        tempj++;
                    }
                    if(count >= 3)
                    {
                        return true;
                    }
                    
                    tempj = j;
                    tempi = i;
                    count = 0;
                    while(tempi < board.size() && board[tempi][tempj] == 1)
                    {
                        count++;
                        tempi++;
                    }
                    if(count >= 3)
                    {
                        return true;
                    }
                    tempi = i;
                    tempj = j;
                    count = 0;
                    while(tempi < board.size() && tempj < board[0].size() && board[tempi][tempj] == 1)
                    {
                        count++;
                        tempi++;
                        tempj++;
                    }
                    if(count >= 3)
                    {
                        return true;
                    }
                    tempi = i;
                    tempj = j;
                    count = 0;
                    while(tempi < board.size() && tempj >= 0 && board[tempi][tempj] == 1)
                    {
                        count++;
                        tempi++;
                        tempj--;
                    }
                    if(count >= 3)
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};

int main()
{
    Board board;
    std::vector<std::vector<int>> arr = {{1, 0, 1}, {1, -1, -1}, {1, -1, 0}};
    std::cout << board.checkWon(arr) << std::endl;;
    
}