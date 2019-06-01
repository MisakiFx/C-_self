//差最小两素数
#include <iostream>
using namespace std;
bool isPrimeNum(int num)
{
    for(int i = 2; i < num; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int num = 0;
    while(cin >> num)
    {
        int num1 = num / 2, num2 = num / 2;
        while(!isPrimeNum(num1) || !isPrimeNum(num2))
        {
            num1--;
            num2++;
        }
        cout << num1 << endl;
        cout << num2 << endl;
    }
}