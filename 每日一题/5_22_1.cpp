#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string str;
    cin >> str;
    string maxDigitStr;
    int maxLength = 0;
    for(int i = 0; i < str.size(); i++)
    {
        int length = 0;
        if(str[i] >= '0' && str[i] <= '9')
        {
            int j;
            length++;
            if(i < str.size() - 1);
            {
                for(j = i + 1; j < str.size(); j++)
                {
                    if(str[j] >= '0' && str[j] <= '9')
                    {
                        length++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if(length > maxLength)
            {
                maxDigitStr = str.substr(i, length);
                maxLength = length;
            }
            i = j - 1;
        }
    }
    cout << maxDigitStr << endl;
}