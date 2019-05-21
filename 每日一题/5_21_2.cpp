/**
 * https://www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355?tpId=85&&tqId=29867&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
 * 题目描述
将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I
输入描述:
每个测试输入包含1个测试用例： I like beijing. 输入用例长度不超过100
输出描述:
依次输出倒置之后的字符串,以空格分割

示例1

输入
I like beijing.

输出
beijing. like I
 */
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1;
    getline(cin, str1);
    while(str1.size() != 0)
    {
        size_t pos = str1.rfind(" ");
        if(pos == string::npos)
        {
            cout << str1;
            return 0;
        }
        string str2 = str1.substr(pos + 1, str1.size() - pos - 1);
        str1.erase(pos, str1.size() - pos);
        cout << str2 << " ";
    }
}