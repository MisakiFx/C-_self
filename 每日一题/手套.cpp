#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//我的错误解法，想的太复杂了，其实正解很简单，一边手套全覆盖，另一边随便拿一只
//根本没必要要求两边拿取的手套种类有交集，还分了奇偶数，太蠢了我
/*
class Gloves {
public:
    bool func(int num1, int num2)
    {
        return (num1 > num2);
    }
    int findMinimum(int n, vector<int> left, vector<int> right) {
        // write code here
        int minCount = 0;
        for(int i = 0; i < left.size(); i++)
        {
            if(left[i] == 0)
            {
                minCount += right[i];
                right[i] = 0;
                continue;
            }
            if(right[i] == 0)
            {
                minCount += left[i];
                left[i] = 0;
            }
        }
        for(int i = 0; i < left.size(); i++)
        {
            if(left[i] == 0)
            {
                n--;
            }
        }
        //std::cout << n << std::endl;
        //std::cout << minCount << std::endl;
        int temp1 = 0, temp2 = 0;
        sort(left.begin(), left.end(), greater<int>());
        sort(right.begin(), right.end(), greater<int>());
        if(n % 2 == 0)
        {
            int i = 0;
            for(i = 0; i < (n / 2 - 1); i++)
            {
                temp1 += left[i] + right[i];
                temp2 += left[i] + right[i];
            }
            temp1 += 1 + right[i] + 1;
            temp2 += 1 + left[i] + 1;
            return minCount + min(temp1, temp2);
        }
        else 
        {
            for(int i = 0; i < (n / 2); i++)
            {
                temp1 += left[i] + right[i];
            }
            return minCount + temp1 + 2;
        }
    }
};
*/
class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        // write code here
        int minCount = 0;
        for(int i = 0; i < left.size(); i++)
        {
            if(left[i] == 0)
            {
                minCount += right[i];
                right[i] = 0;
                continue;
            }
            if(right[i] == 0)
            {
                minCount += left[i];
                left[i] = 0;
            }
        }
        std::cout << minCount << std::endl;
        int temp1 = 0, temp2 = 0;//两边最少的全覆盖手套需要拿取数
        //最少拿取数 = 手套和 - 最小值 + 1
        int leftMin = INT_MAX, rightMin = INT_MAX;
        for(int i = 0; i < left.size(); i++)
        {
            temp1 += left[i];
            temp2 += right[i];
            if(left[i] != 0 && left[i] < leftMin)
            {
                leftMin = left[i];
            }
            if(right[i] != 0 && right[i] < rightMin)
            {
                rightMin = right[i];
            }
        }
        std::cout << temp1 << std::endl;
        std::cout << temp2 << std::endl;
        temp1 = temp1 - leftMin + 1;
        temp2 = temp2 - rightMin + 1;
        return minCount + min(temp1, temp2) + 1;
    }
};
int main()
{
    Gloves glo;
    int min = glo.findMinimum(4, {0, 7, 1, 6}, {1, 5, 0, 6});
    std::cout << min << std::endl;
}