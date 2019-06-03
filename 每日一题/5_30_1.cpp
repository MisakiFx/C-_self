//https://www.nowcoder.com/practice/e1bb714eb9924188a0d5a6df2216a3d1?tpId=8&&tqId=11055&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
/**
 * 题目描述
对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。

给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为-1代表是对方玩家的棋子。

测试样例：
[[1,0,1],[1,-1,-1],[1,-1,0]]
返回：true
 */
//暴力旧完事了
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