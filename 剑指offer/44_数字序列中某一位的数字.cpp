#include <iostream>
#include <cmath>

//获取digit位数一共有多少个
int GetDigit(int digit)
{
    if(digit == 1)
    {
        return 10;
    }
    return 9 * pow(10, digit - 1);
}
//计算digit位数的第一个数是多少
int GetFirst(int digit)
{
    if(digit == 1)
    {
        return 0;
    }
    return pow(10, digit - 1);
}

//获取从digit位数第一个数算起index下标的数字是多少
int GetIndex(int index, int digit)
{
    int first = GetFirst(digit);
    int number = first + index / digit;
    int pos = digit - (index % digit) - 1;
    return (int)(number / (pow(10, pos))) % 10;
}

int main()
{
    int num = 0;
    while(std::cin >> num)
    {
        if(num < 0)
        {
            return -1;
        }
        //位数，从一位数开始算起
        int digit = 1;
        while(1)
        {
            int number = GetDigit(digit);
            if(num < digit * number)
            {
                std::cout << GetIndex(num, digit) << std::endl;
                break;
            }
            num -= number * digit;
            digit++;
        }
    }
}


