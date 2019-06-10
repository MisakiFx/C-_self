#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1;
    while(cin >> str1)
    {
        string str2;
        for(int i = str1.size() - 1; i >= 0; i--)
        {
            str2 += str1[i];
        }
        cout << str2 << endl;
    }
}