#include <iostream>
//#include <stdint>
using namespace std;
int main()
{
    int num1 = 0;
    while(cin >> num1)
    {
        for(int i = 0; i < num1; i++)
        {
            int num;
            cin >> num;
            if(num <= 3)
            {
                cout << "000" << num;
                continue;
            }
            int f1 = 2;
            int f2 = 3;
            int f3;
            for(int i = 4; i <= num; i++)
            {
                f3 = f1 + f2;
                f1 = f2;
                f2 = f3;
                f2 = f2 % 10000;
            }
            printf("%04d", f2);
        }
        cout << endl;
    }
}