// write your code here cpp
//纯粹智力题，推导公式直接套公式
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    //根据一大堆推导可以得出x = 5 ^ n - 4;
    //给老猴子的桃子为:4 ^ n - 4 + n;
    int n = 0;
    while(cin >> n)
    {
        if(n == 0)
        {
            break;
        }
        std::cout << std::fixed;
        std::cout.precision(0);
        cout << (pow(5, n) - 4) << " " << (pow(4, n) - 4 + n) << endl;
    }
}