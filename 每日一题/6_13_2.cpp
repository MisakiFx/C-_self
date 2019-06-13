#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    int flag = 0;
    while(cin >> str)
    {    
        int i;
        for(i = 0; i < str.size(); i++)
        {
            int j;
            flag = 0;
            for(j = i + 1; j < str.size(); j++)
            {
                if(str[j] == str[i])
                {
                    flag = 1;
                    str.erase(j, 1);
                    j--;
                }
            }
            if(flag == 0)
            {
                cout << str[i] << endl;
                break;
            }
        }
        if(i == str.size())
        cout << "-1" << endl;
    }
}