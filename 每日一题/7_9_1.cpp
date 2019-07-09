#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int year1, year2;
    int month1, month2;
    int day1, day2;
    int arr[] = {62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62};
    int arr2[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while(cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
    {
        int profit = 0;
        if(year1 == year2)
        {
            if(month1 == month2)
            {
                if(month1 == 2 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 11)
                {
                    profit += day2 - day1 + 1;
                }
                else
                {
                    profit += (day2 - day1 + 1) * 2;
                }
            }
            else
            {
                if(month1 == 2 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 11)
                {
                    profit += arr2[month1 - 1] - day1 + 1;
                }
                else
                {
                    profit += (arr2[month1 - 1] - day1 + 1) * 2;
                }
                for(int i = month1; i < month2 - 1; i++)
                {
                    profit += arr[i];
                }
                if(month2 == 2 || month2 == 3 || month2 == 5 || month2 == 7 || month2 == 11)
                {
                    profit += day2;
                }
                else
                {
                    profit += day2 * 2;
                }
                if(month1 <= 2 && month2 > 2)
                {
                    profit += 1;
                }
            }
        }
        else
        {
            if(month1 == 2 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 11)
            {
                profit += arr2[month1 - 1] - day1 + 1;
            }
            else
            {
                profit += (arr2[month1 - 1] - day1 + 1) * 2;
            }
            for(int i = month1; i < 12; i++)
            {
                profit += arr[i];
            }
            if(year1 % 400 == 0 || (year1 % 4 == 0) && (year1 % 100 != 0) && (month1 <= 2))
            {
                profit += 1;
            }
            for(int i = year1 + 1; i < year2; i++)
            {
                for(int j = 0; j < 12; j++)
                {
                    profit += arr[j];
                }
                if(i % 400 == 0 || (i % 4 == 0) && (i % 100 != 0))
                {
                    profit += 1;
                }
            }
            for(int i = 0; i < month2 - 1; i++)
            {
                profit += arr[i];
            }
            if(month2 == 2 || month2 == 3 || month2 == 5 || month2 == 7 || month2 == 11)
            {
                profit += day2;
            }
            else
            {
                profit += day2 * 2;
            }
            if(year2 % 400 == 0 || (year2 % 4 == 0) && (year2 % 100 != 0) && (month2 > 2))
            {
                profit += 1;
            }
        }
        cout << profit << endl;
    }
}