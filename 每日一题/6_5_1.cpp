#include <iostream>
using namespace std;
int main()
{
    int num = 0;
    while(cin >> num)
    {
        int count = 0;
        while(num)
        {
            if((num & 1) == 1)
            {
                count++;
            }
            num >>= 1;
        }
        cout << count << endl;
    }
}