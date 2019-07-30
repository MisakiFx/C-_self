//https://www.nowcoder.com/questionTerminal/59ac416b4b944300b617d4f7f111b215
/**
 * 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int Add(int num1, int num2)
    {
        int result = num1 ^ num2;
        while(num2)
        {
            result = num1 ^ num2;
            num2 = num1 & num2;
            num2 <<= 1;
            num1 = result;
        }
        return result;
    }
};
int main()
{

}