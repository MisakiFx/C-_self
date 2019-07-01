#include <iostream>
#include <climits>
using namespace std;
int main()
{
    double n;
    double r;
    while(cin >> n >> r)
    {
        double c = 2 * r * 3.14;
        if(n <= c)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}