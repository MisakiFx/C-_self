//https://www.nowcoder.com/practice/4284c8f466814870bae7799a07d49ec8?tpId=85&amp;&amp;tqId=29852&amp;rp=1&amp;ru

/**
 * ????
??????????????????1??????1?2?3.......
??????????????????????????????K? ????????????K?????(??1?K)?????K+X(X?K????1??????)???? ?????????N?????????????M???????????????????????
???
N = 4?M = 24?
4->6->8->12->18->24
??????????5??????4?????24???
????:
???????????N?M??????? (4 ? N ? 100000) (N ? M ? 100000)
????:
?????????????,????????-1

??1

??
4 24

??
5
 */
/**
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
int main()
{
    int n = 0, m = 0;
    while(cin >> n >> m)
    {
        vector<int> board(m + 1, INT_MAX);
        board[n] = 0;//第0步
        for(int i = n; i <= m; i++)
        {
            if(board[i] == INT_MAX)
            {
                continue;
            }
            for(int j = 2; (j * j) <= i; j++)
            {
                if(i % j == 0)
                {
                    if(i + j <= m)
                    board[i + j] = min(board[i] + 1, board[i + j]);
                    if(i + (i / j) <= m)
                    board[i + (i / j)] = min(board[i] + 1, board[i + (i / j)]);
                }
            }
        }
        if(board[m] == INT_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << board[m] << endl;
        }
    }
}
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
void GetPrime(int num, vector<int>& prime)
{
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            prime.push_back(i);
            if((num / i) != i)
            {
                prime.push_back(num / i);
            }
        }
    }
}
int GetSteps(int n, int m)
{
    vector<int> steps(m + 1, 0);
    steps[n] = 1;
    for(int i = n; i < m; i++)
    {
        if(steps[i] == 0)
        {
            continue;
        }
        vector<int> prime;
        GetPrime(i, prime);
        for(int j = 0; j < prime.size(); j++)
        {
            if(((prime[j] + i) <= m) && (steps[i + prime[j]] != 0))
            {
                steps[i + prime[j]] = min(steps[i + prime[j]], steps[i] + 1);
            }
            else if((prime[j] + i) <= m)
            {
                steps[i + prime[j]] = steps[i] + 1;
            }
        }
    }
    if(steps[m] == 0)
    {
        return -1;
    }
    else
    {
        return steps[m] - 1;
    }
}
int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        cout << GetSteps(n, m) << endl;
    }
}