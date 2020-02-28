#include <iostream>
#include <math.h>
#define g_max 6

//递归解法
/*
void Probablity(int ori, int cur, int sum, int* arr)
{
    if(cur == 0)
    {
        arr[sum - ori] += 1;
    }
    else 
    {
        for(int i = 1; i <= g_max; i++)
        {
            Probablity(ori, cur - 1, sum + i, arr);
        }
    }
}
int main()
{
    int number;
    while(std::cin >> number)
    {
        int maxSum = g_max * number;
        int* arr = new int[maxSum - number + 1]();
        Probablity(number, number, 0, arr);
        int total = std::pow((double)g_max, number);
        for (int i = number; i <= maxSum; i++)
        {
            double ratio = (double)arr[i - number] / total;
            printf("%lf\n", ratio);
        }
        delete[] arr;
    }
}
*/
int main()
{
    int number = 0;
    while(std::cin >> number)
    {
        int *Probility[2] = {0};
        Probility[0] = new int[g_max * number + 1]();
        Probility[1] = new int[g_max * number + 1]();
        int flag = 0;
        for(int i = 1; i <= g_max; i++)
        {
            Probility[flag][i] = 1;
        }
        for(int k = 2; k <= number; k++)
        {
            for(int i = 0; i < k; i++)
            {
                Probility[1 - flag][i] = 0;
            }
            for(int i = k; i <= g_max * k; i++)
            {
                Probility[1 - flag][i] = 0;
                for(int j = 1; j <= i && j <= g_max; j++)
                {
                    Probility[1 - flag][i] += Probility[flag][i - j];
                }
            }
            flag = 1 - flag;
        }
        int total = std::pow((double)g_max, number);
        for(int i = number; i <= g_max * number; i++)
        {
            double ratio = (double)Probility[flag][i] / total;
            printf("%lf\n", ratio);
        }
        delete[] Probility[0];
        delete[] Probility[1];
    }
}