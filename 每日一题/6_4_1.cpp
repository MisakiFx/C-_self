#include <iostream>
using namespace std;
int main()
{
    int year = 0;
    int month = 0;
    int days = 0;
    while(cin >> year >> month >> days)
    {
        int outDay = 0;
        int daysOfMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i = 1; i < month; i++)
        {
            outDay += daysOfMonth[i];
        }
        outDay += days;
        if(((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month > 2)
        {
            outDay += 1;
        }
        cout << outDay << endl;
    }
}