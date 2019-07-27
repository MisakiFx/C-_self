#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    while(getline(cin, str))
    {
        string res;
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                res.push_back(str[i]);
            }
        }
        cout << res << endl;
    }
}