//https://www.nowcoder.com/practice/4b1658fd8ffb4217bc3b7e85a38cfaf2?tpId=37&&tqId=21309&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
/**
 * 题目描述
功能: 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
    
输入: 一个byte型的数字
    
输出: 无
     
返回: 对应的二进制数字中1的最大连续数
输入描述:
输入一个byte数字

输出描述:
输出转成二进制之后连续1的个数

示例1
输入
复制
3
输出
复制
2
*/
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int a = 0;
    while(cin >> a)
    {
        int cur = 0;
        int max = 0;
        while(a)
        {
            if((a & 1) == 1)
            {
                cur++;
                if(cur > max)
                {
                    max = cur;
                }
            }
            else
            {
                cur = 0;
            }
            a = a >> 1;
        }
        cout << max << endl;
        }
}