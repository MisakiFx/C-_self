// write your code here cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    while(cin >> str)
    {
        string res;
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == '_')
            {
                res.push_back(str[i + 1] - ' ');
                i++;
            }
            else
            {
                res.push_back(str[i]);
            }
        }
        cout << res << endl;
    }
}