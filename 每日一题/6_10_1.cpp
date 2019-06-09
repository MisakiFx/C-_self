#include <iostream>
using namespace std;
int main()
{
    int num = 0;
    while(cin >> num)
    {
        int count = 0;
        if(num == 0)
        {
            break;
        }
        while(num >= 2)
        {
            if(num == 2)
            {
                count++;
                break;
            }
            int curCount = 0;
            curCount += (num / 3);
            num = num % 3;
            num += curCount;
            count += curCount;
        }
        cout << count << endl;
    }
}