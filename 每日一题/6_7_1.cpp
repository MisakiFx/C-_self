#include <iostream>
using namespace std;
int main()
{
    int num = 0;
    int arr[] = {2, 3, 2, 4};
    while(cin >> num)
    {
        if(num < 3)
        {
            cout << -1;
            continue;
        }
        cout << arr[(num - 3) % 4]  << endl;
    }
}
