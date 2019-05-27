//最小公倍数
#include <iostream>
using namespace std;
int main()
{
    int num1 = 0;
    int num2 = 0;
    cin >> num1 >> num2;
    int max = 1;
    for(int i = 2; i <= (num1 < num2 ? num1 : num2); i++)
    {
        if(num1 % i == 0 && num2 % i == 0)
        {
            max = i;
        }
    }
    int min = num1 * num2 / max;
    cout << min << endl;
}