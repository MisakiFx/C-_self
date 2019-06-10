#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1;
    string str2;
    while(cin >> str1 >> str2)
    {
        string curString;
        string maxString;
        for(int i = 0; i < str1.size(); i++)
        {
            if(str1[i] >= 'A' && str1[i] <= 'Z')
            {
                str1[i] -= ' ';
            }
        }
        for(int i = 0; i < str2.size(); i++)
        {
            if(str2[i] >= 'A' && str2[i] <= 'Z')
            {
                str2[i] -= ' ';
            }
        }
        for(int i = 0; i < str1.size(); i++)
        {
            for(int j = 0; j < str2.size(); j++)
            {
                if(str1[i] == str2[j])
                {
                    int m = i;
                    int n = j;
                    while(str1[m] == str2[n] && str1[m] != '\0')
                    {
                        curString += str1[m];
                        //cout << curString << endl;
                        m++;
                        n++;
                    }
                    if(curString.size() > maxString.size())
                    {
                        maxString = curString;
                    }
                    curString.resize(0);
                }
            }
        }
        cout << maxString.size() << endl;
    }
}