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
        if(carryFlag == true)
        {
            res.push('1');
        }
        while(!res.empty())
        {
            cout << res.top();
            res.pop();
        }
        cout << endl;
    }
}
