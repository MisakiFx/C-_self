//https://www.nowcoder.com/practice/1b46eb4cf3fa49b9965ac3c2c1caf5ad?tpId=37&&tqId=21285&rp=1&ru=/
/**
 * 题目描述
涉及知识点：

输入描述:
输入一个整数

输出描述:
计算整数二进制中1的个数

示例1

输入
5

输出
2
 */
#include <iostream>
using namespace std;
int main()
{
    int num = 0;
    while(cin >> num)
    {
        int count = 0;
        while(num)
        {
            if((num & 1) == 1)
            {
                count++;
            }
            num >>= 1;
        }
        cout << count << endl;
    }
}