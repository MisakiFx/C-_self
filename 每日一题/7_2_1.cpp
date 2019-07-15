//https://www.nowcoder.com/questionTerminal/22243d016f6b47f2a6928b4313c85387
/**
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */
#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//    int jumpFloorII(int number) {
//        vector<int> steps(number + 1, 0);
//        steps[0] = 1;
//        for(int i = 1; i < steps.size(); i++)
//        {
//            steps[i] = 0;
//            for(int j = i - 1; j >= 0; j--)
//            {
//                steps[i] += steps[j];
//            }
//        }
//        return steps[number];
//    }
//};
class Solution {
public:
    int jumpFloorII(int number) {
        //根据类推公式得
        //n级台阶就有2 ^ (n - 1)种跳法
        return 1 << (number - 1);
    }
};
int main()
{

}