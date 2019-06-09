#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1, str2;
    while(cin >> str1 >> str2)
    {
        string maxString;
        int i = 0;
        if(str1.size() > str2.size())
        {
            swap(str1, str2);
        }
        for(int i = 0; i < str1.size(); i++)
        {
            for(int j = 0; j <= str2.size(); j++)
            {
                string curString;
                if(str1[i] == str2[j])
                {
                    int m = i;
                    int n = j;
                    while(str1[m] == str2[n])
                    {
                        curString += str1[m];
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
        cout << maxString << endl;
    }
}