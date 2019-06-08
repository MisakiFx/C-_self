#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1;
    string str2;
    while(cin >> str1 >> str2)
    {
        int i = 0;
        int j = 0;
        while(str1[i] != '\0' && str2[j] != '\0')
        {
            if(str1[i] == '?')
            {
                i++;
                j++;
                continue;
            }
            if(str1[i] == '*')
            {
                i++;
                if(str1[i] == '?')
                {
                    i++;
                    j++;
                }
                while(str2[j] != str1[i] && str2[j] != '\0')
                {
                    j++;
                }
                if(str2[j] != str1[i] && str2[j] == '\0')
                {
                    continue;
                }
                else if(str2[j] == str1[i] && str2[j] == '\0')
                {
                    continue;
                }
                else
                {
                    j++;
                    i++;
                    while(str2[j] == str2[j - 1] && str2[j] != str1[i])
                    {
                        j++;
                    }
                    continue;
                }
            }
             if(str1[i] >= 'A' && str1[i] <= 'Z')
            {
                str1[i] -= ' ';
            }
            if(str2[j] >= 'A' && str2[j] <= 'Z')
            {
                str2[2] -= ' ';
            }
            if(str1[i] != str2[j])
            {
                //cout << str1[i] << " " << str2[j] << endl;
                break;
            }
            i++;
            j++;
        }
        if(str1[i] == '\0' && str2[j] == '\0')
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
}
