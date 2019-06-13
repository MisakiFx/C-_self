#include <iostream>
#include <vector>
using namespace std;
int GetMaxPrime(int num1, int num2)
{
    int min = num1 < num2 ? num1 : num2;
    for(int i = min; i > 0; i--)
    {
        if(num1 % i == 0 && num2 % i == 0)
        {
            return i;
        }
    }
    return 1;
}
int main()
{
    int num = 0;
    int ability = 0;
    while(cin >> num >> ability)
    {
        int b;
        for(int i = 0; i < num; i++)
        {
            cin >> b;
            if(ability >= b)
            {
                ability += b;
            }
            else
            {
                ability += GetMaxPrime(ability, b);
            }
        }
        cout << ability << endl;
    }
}