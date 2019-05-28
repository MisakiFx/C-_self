//括号匹配问题
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