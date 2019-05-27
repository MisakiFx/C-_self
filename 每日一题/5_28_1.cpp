//字符串排序规则
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int num = 0;
    cin >> num;
    int lex = 1, len = 1;
    string str1, str2;
    cin >> str1;
    for(int i = 1; i < num; i++)
    {
        str2 = "";
        cin >> str2;
        if(str1 > str2)
        {
            lex = 0;
        }
        if(str1.size() > str2.size())
        {
            len = 0;
        }
        str1 = str2;
    }
    if(lex == 1 && len == 1)
    {
        cout << "both" << endl;
    }
    if(lex == 1 && len != 1)
    {
        cout << "lexicographically" << endl;
    }
    if(lex != 1 && len == 1)
    {
        cout << "lengths" << endl;
    }
    if(lex == 0 && len == 0)
    {
        cout << "none" << endl;
    }
}