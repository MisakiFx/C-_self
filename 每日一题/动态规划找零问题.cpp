#include <iostream>
using namespace std;
int main()
{
    int value[] = {2, 3, 5, 10};
    int coins[] = {2, 2, 2, 2};
    int m = 0;
    while (cin >> m)
    {
        int cost[110] = {0};
        if(m == 0)
        {
            break;
        }
        cost[0] = 1;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < coins[i]; j++)
            {
                for (int k = m; k >= value[i]; k--)
                {
                    if(cost[k - value[i]] == 1)
                    {
                        cost[k] = 1;
                    }
                }
            }
        }
        if(cost[m] == 1)
        {
            cout << "Y" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
        
    }
}
