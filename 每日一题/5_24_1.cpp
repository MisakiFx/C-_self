/*
变回文数的方法
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1;
    cin >> str1;
    string str2;
    cin >> str2;
    int count = 0;
    for(int i = 0; i < str1.size(); i++)
    {
        string temp = str1;
        temp.insert(i, str2);
        string temp2 = temp;
        temp2.assign(temp2.rbegin(), temp2.rend());
        if(temp2 == temp)
        {
            count++;
        }
    }
    string temp = str1;
    temp.append(str2);
    string temp2 = temp;
    temp2.assign(temp2.rbegin(), temp2.rend());
    if(temp2 == temp)
    {
        count++;
    }
    cout << count << endl;
}