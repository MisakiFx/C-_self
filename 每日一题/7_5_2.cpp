//数学递推的递推公式，或者找规律的答案
#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >> n)
    {
        if(n == 0)
        {
            break;
        }
        int count = 0;
        uint64_t sum = 1;
        while(sum < n)
        {
            sum *= 3;
            count++;
        }
        cout << count << endl;
    }
}