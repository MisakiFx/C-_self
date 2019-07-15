#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
int main()
{
    string str;
    while(getline(cin, str))
    {
        stack<string> res;
        int cur = 0;
        string word;
        for(int i = 0; i < str.size(); i++)
        {
            if(isalpha(str[i]))
            {
                word.push_back(str[i]);
            }
            else
            {
                if(word != "")
                {
                    res.push(word);
                    word.clear();
                }
            }
        }
        if(word != "")
        {
            res.push(word);
        }
        if(!res.empty())
        {
            cout << res.top();
            res.pop();
        }
        while(!res.empty())
        {
            cout << " " << res.top();
            res.pop();
        }
    }
}