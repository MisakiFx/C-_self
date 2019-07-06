// write your code here cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string key;
    while(getline(cin, key))
    {
        string result;
        for(int i = 0; i < key.size(); i++)
        {
            if(key[i] == ' ')
            {
                cout << " ";
            }
            if(key[i] != ' ')
            {
                char temp;
                if(key[i] <= 'Z' && key[i] >= 'F')
                {
                   temp = key[i] - 5;
                }
                else
                {
                   temp = key[i] + 21;
                }
                cout << temp;
            }
        }
        cout << endl;
    }
}