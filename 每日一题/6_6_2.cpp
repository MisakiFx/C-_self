#include <iostream>
#include <string>
#include <vector>
using namespace std;
int NumOfPoker(string str)
{
    int count = 1;
    for(size_t i = 0; i < str.size(); i++)
    {
        if(str[i] == ' ')
        {
            count++;
        }
    }
    return count;
}
int PriceOfPoker(string str)
{
    int res = 0;
    /*
    if(str == "joker")
    {
        res = 14;
    }
    if(str == "JOKER")
    {
        res = 15;
        return res;
    }
    */
    if(str[0] == '3')
    {
        res = 1;
    }
    if(str[0] == '4')
    {
        res = 2;
    }
    if(str[0] == '5')
    {
        res = 3;
    }
    if(str[0] == '6')
    {
        res = 4;
    }
    if(str[0] == '7')
    {
        res = 5;
    }
    if(str[0] == '8')
    {
        res = 6;
    }
    if(str[0] == '9')
    {
        res = 7;
    }
    if(str[0] == '1')
    {
        res = 8;
    }
    if(str[0] == 'J')
    {
        res = 9;
    }
    if(str[0] == 'Q')
    {
        res = 10;
    }
    if(str[0] == 'K')
    {
        res = 11;
    }
    if(str[0] == 'A')
    {
        res = 12;
    }
    if(str[0] == '2')
    {
        res = 13;
    }
    return res;
}
int main()
{
    string str;
    while(getline(cin, str))
    {
        string player1 = str.substr(0, str.find('-'));//玩家一
        string player2 = str.substr(str.find('-') + 1);//玩家二
        //判断胜负
        if(player1 == "joker JOKER")
        {
            cout << player1 << endl;
        }
        else if(player2 == "joker JOKER")
        {
            cout << player2 << endl;
        }
        else if(NumOfPoker(player1) == NumOfPoker(player2))
        {
            if(PriceOfPoker(player1) > PriceOfPoker(player2))
            {
                cout << player1 << endl;
            }
            else
            {
                cout << player2 << endl;
            }
        }
        else if(NumOfPoker(player1) == 4)
        {
            cout << player1 << endl;
        }
        else if(NumOfPoker(player2) == 4)
        {
            cout << player2 << endl;
        }
        else 
        {
            cout << "ERROR" << endl;
        }
    }
}