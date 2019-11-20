//https://exam.nowcoder.com/cts/17054790/summary?id=3106F5DB0B7571F6#4/{%22uid%22%3A%223106F5DB0B7571F6%22%2C%22type%22%3A%224%22%2C%22index%22%3A1}
#include <iostream>
#include <vector>
#include <algorithm>
//深度优先搜索算法，用一颗深度优先遍历二叉树即可，加上剪枝
//用一颗二叉树类比
int bfs(std::vector<int>& arr, int index, int sum, int mul)
{
    int count = 0;
    for(int i = index; i < arr.size(); i++)
    {
        sum += arr[i];
        mul *= arr[i];
        if(sum > mul)
        {
            count += 1 + bfs(arr, i + 1, sum, mul);
        }
        //只有还为1时还有可能后面还有符合条件的可能
        else if(arr[i] == 1)
        {
            count += bfs(arr, i + 1, sum, mul);
        }
        else 
        {
            break;//回溯
        }
        sum -= arr[i];
        mul /= arr[i];
        while(i + 1 < arr.size() && arr[i] == arr[i + 1])
        {
            i++;
        }
    }
    return count;
}

int main()
{
    int num = 0;
    while(std::cin >> num)
    {
        std::vector<int> arr(num, 0);
        for(int i = 0; i < num; i++)
        {
            std::cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        std::cout << (bfs(arr, 0, 0, 1)) << std::endl;
    }
}