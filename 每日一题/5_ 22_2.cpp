#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    int hashTable[10] = {0};
    int count = 0;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            hashTable[str[i] - '0']++;
            count++;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        if(hashTable[i] >= count / 2)
        {
            cout << i;
            return 0;
        }
    }
}