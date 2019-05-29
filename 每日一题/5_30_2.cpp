//判断密码强弱
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    while(cin >> str)
    {
        int grade = 0;
        int numOfBigAlpha = 0;
        int numOfSmallAlpha = 0;
        int numOfDigit = 0;
        int numOfOther = 0;
        if(str.size() <= 4)
        {
            grade += 5;
        }
        else if(str.size() >= 5 && str.size() <= 7)
        {
            grade += 10;
        }
        else if(str.size() >= 8)
        {
            grade += 25;
        }
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                numOfSmallAlpha++;
            }
            else if(str[i] >= 'A' && str[i] <= 'Z')
            {
                numOfBigAlpha++;
            }
            else if(str[i] >= '0' && str[i] <= '9')
            {
                numOfDigit++;
            }
            else
            {
                numOfOther++;
            }
        }
        if(numOfSmallAlpha == 0 || numOfBigAlpha == 0)
        {
            grade += 10;
        }
        else if(numOfSmallAlpha != 0 && numOfBigAlpha != 0)
        {
            grade += 25;
        }
        if(numOfDigit == 1)
        {
            grade += 10;
        }
        else if(numOfDigit > 1)
        {
            grade += 25;
        }
        if(numOfOther == 1)
        {
            grade += 10;
        }
        else if(numOfOther > 1)
        {
            grade += 25;
        }
        if(numOfDigit != 0 && ((numOfSmallAlpha + numOfBigAlpha) != 0))
        {
            grade += 2;
        }
        if(numOfDigit != 0 && ((numOfSmallAlpha + numOfBigAlpha) != 0) && numOfOther != 0)
        {
            grade += 3;
        }
        if(numOfDigit != 0 && numOfSmallAlpha != 0 && numOfBigAlpha != 0 && numOfOther != 0)
        {
            grade += 5;
        }
        if(grade >= 90)
        {
            cout << "VERY_SECURE" << endl;
        }
        else if(grade >= 80)
        {
            cout << "SECURE" << endl;
        }
         else if(grade >= 70)
        {
            cout << "VERY_STRONG" << endl;
        }
         else if(grade >= 60)
        {
            cout << "STRONG" << endl;
        }
         else if(grade >= 50)
        {
            cout << "AVERAGE" << endl;
        }
         else if(grade >= 25)
        {
            cout << "WEAK" << endl;
        }
         else if(grade >= 0)
        {
            cout << "VERY_WEAK" << endl;
        }
    }
}