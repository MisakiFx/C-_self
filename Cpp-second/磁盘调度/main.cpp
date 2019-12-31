#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>

int main()
{
    srand(time(nullptr));
    std::vector<int> arr, arrTemp;
    for(int i = 0;i < 15; i++)
    {
        arr.push_back(rand() % 200 + 1);
    }
    std::sort(arr.begin(), arr.end());
    std::vector<int>::iterator it = arr.begin();
    while(it != arr.end() && *it < 100)
    {
        arrTemp.push_back(*it);
        it = arr.erase(it);
    }
    for(int i = arrTemp.size() - 1; i >= 0; i--)
    {
        arr.push_back(arrTemp[i]);
    }
    for(const auto e : arr)
    {
        std::cout << e << " ";
    }
    double sum = 0;
    for(int i = 0; i < arr.size() - 1; i++)
    {
        sum += abs(arr[i] - arr[i + 1]);
    }
    std::cout << std::endl;
    std::cout << "sum = " << sum << std::endl;
    std::cout << "avg = " << std::fixed << std::setprecision(1) << sum / 15 << std::endl;
}