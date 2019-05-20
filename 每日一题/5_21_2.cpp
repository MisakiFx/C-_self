#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1;
    getline(cin, str1);
    while(str1.size() != 0)
    {
        size_t pos = str1.rfind(" ");
        if(pos == string::npos)
        {
            cout << str1;
            return 0;
        }
        string str2 = str1.substr(pos + 1, str1.size() - pos - 1);
        str1.erase(pos, str1.size() - pos);
        cout << str2 << " ";
    }
}