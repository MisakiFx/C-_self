#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isWin(const vector<string>& chess, int i, int j, char ch)
{
    //左右判断
    int n = i, m = j;
    int count = 0;
    while(m >= 0 && chess[n][m] == ch)
    {
        count++;
        m--;
    }
    n = i;
    m = j + 1;
    while(m < 20 && chess[n][m] == ch)
    {
        count++;
        m++;
    }
    if(count >= 5)
    {
        return true;
    }
    //上下判断
    count = 0;
    n = i;
    m = j;
    while(n >= 0 && chess[n][m] == ch)
    {
        count++;
        n--;
    }
    n = i + 1;
    m = j;
    while(n < 20 && chess[n][m] == ch)
    {
        count++;
        n++;
    }
    if(count >= 5)
    {
        return true;
    }
    //主对角线判断
    count = 0;
    n = i;
    m = j;
    while(n >= 0 && m >= 0 && chess[n][m] == ch)
    {
        count++;
        m--;
        n--;
    }
    n = i + 1;
    m = j + 1;
    while(n < 20 && m < 20 && chess[n][m] == ch)
    {
        count++;
        m++;
        n++;
    }
    if(count >= 5)
    {
        return true;
    }
    //副对角线判断
    count = 0;
    n = i;
    m = j;
    while(n >= 0 && m < 20 && chess[n][m] == ch)
    {
        count++;
        n--;
        m++;
    }
    n = i + 1;
    m = j - 1;
    while(n < 20 && m >= 0 && chess[n][m] == ch)
    {
        count++;
        n++;
        m--;
    }
    if(count >= 5)
    {
        return true;
    }
    return false;
}
int main()
{
    vector<string> chess(20, string(20, '\0'));
    while(cin >> chess[0])
    {
        for(int i = 1; i < 20; i++)
        {
            cin >> chess[i];
        }
        int flag = false;
        for(int i = 0; i < 20; i++)
        {
            if(flag == true)
            {
                break;
            }
            for(int j = 0; j < 20; j++)
            {
                if(chess[i][j] == '*')
                {
                    flag = isWin(chess, i, j, '*');
                    if(flag == true)
                    {
                        break;
                    }
                }
                else if(chess[i][j] == '+')
                {
                    flag = isWin(chess, i, j, '+');
                    if(flag == true)
                    {
                        break;
                    }
                }
            }
        }
        if(flag == false)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
}