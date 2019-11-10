#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> arr = {1, 10, 3, 4, 5, 2, 5, 7};
    std::sort(arr.begin(), arr.end(), std::less<int>());//通过仿函数的方式传入，从小到大排序
    for(auto e : arr)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    std::sort(arr.begin(), arr.end(), //lambda表达式传入
        [](int a, int b)->bool
        {
            return a > b;
        }
    );
    for(auto e : arr)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}