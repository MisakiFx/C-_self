//https://www.nowcoder.com/practice/d8acfa0619814b2d98f12c071aef20d4?tpId=8&&tqId=11039&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
/**
 * 题目描述
对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。

给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。

测试样例：
"(()())",6
返回：true

测试样例：
"()a()()",7
返回：false

测试样例：
"()(()()",7
返回：false
*/
#include <iostream>
#include <stack>
using namespace std;
class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        stack<char> list;
        for(int i = 0; i < n; i++)
        {
            if(A[i] == '(')
            {
                list.push(A[i]);
            }
            if(A[i] == ')')
            {
                if(list.empty())
                {
                    return false;
                }
                list.pop();
            }
        }
        if(list.empty())
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Parenthesis p;
    bool a = p.chkParenthesis("(()()()())", 10);
    bool b = p.chkParenthesis("()(", 3);
    cout << a << endl;
    cout << b << endl;
}