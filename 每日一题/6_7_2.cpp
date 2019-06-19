//https://www.nowcoder.com/practice/5821836e0ec140c1aa29510fd05f45fc?tpId=37&&tqId=21301&rp=1&ru=/
/**
 * 题目描述
请设计一个算法完成两个超长正整数的加法。

输入描述:
输入两个字符串数字

输出描述:
输出相加后的结果，string型

示例1
输入
99999999999999999999999999999999999999999999999999
1

输出
100000000000000000000000000000000000000000000000000
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    string num1;
    string num2;
    while(cin >> num1 >> num2)
    {
        stack<char> res;
        int len = num1.size() < num2.size() ? num1.size() : num2.size();
        int len2 = num1.size() > num2.size() ? num1.size() : num2.size();
        string& longNum = num1.size() > num2.size() ? num1 : num2;
        string& shortNum = num1.size() <= num2.size() ? num1 : num2;
        bool carryFlag = false;
        //cout << len << " " << len2 << endl;
        //将两个字符串进行逐位相加，并且标记进位，直到短字符串结束为止
        for(int i = len2 - 1, j = len - 1; j >= 0; i--, j--)
        {
            int curRes;
            if(carryFlag == true)
            {
                curRes = (longNum[i] - '0') + (shortNum[j] - '0') + 1;
                carryFlag = false;
            }
            else
            {
                curRes = (longNum[i] - '0') + (shortNum[j] - '0');
            }
            if(curRes >= 10)
            {
                carryFlag = true;
                curRes %= 10;
            }
            res.push('0' + curRes);
        }
        //将长字符串多余的部分也压入结果栈，同时标记进位
        for(int i = len2 - len - 1; i >= 0; i--)
        {
            int curRes;
            if(carryFlag == true)
            {
                curRes = (longNum[i] - '0') + 1;
                carryFlag = false;
            }
            else
            {
                curRes = (longNum[i] - '0');
            }
            if(curRes >= 10)
            {
                carryFlag = true;
                curRes %= 10;
            }
            res.push('0' + curRes);
        }
        //最后如果还标记有进位则需要在开头压入1
        if(carryFlag == true)
        {
            res.push('1');
        }
        //输出
        while(!res.empty())
        {
            cout << res.top();
            res.pop();
        }
        cout << endl;
    }
}
/**
 * #include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string addStrings(string num1, string num2) {
//由低位向高位相加
int i = num1.size() - 1;
int j = num2.size() - 1;
string result = "";
//当前位的相加结果
int carry = 0;
while (i >= 0 || j >= 0)
{ if (i >= 0) {
carry += num1[i] - '0';
}
if (j >= 0) {
carry += num2[j] - '0';
}
//当前为的最大值不大于10
result += (char)(carry % 10 + '0');
//如果大于10,向上进一位
carry /= 10;
i--;
j--;
}
//相加完之后，如果还有进位，则再加1
if (carry == 1)
{ result += '1';
}
//整体逆置
reverse(result.begin(), result.end());
return result;
}
int main()
{
string s1, s2;
while(cin>>s1>>s2)
{
cout<<addStrings(s1, s2)<<endl;
}
return 0;
}
 */