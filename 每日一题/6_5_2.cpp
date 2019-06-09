//https://www.nowcoder.com/practice/365d5722fff640a0b6684391153e58d8?tpId=49&&tqId=29337&rp=1&ru=/
/**
 * 题目描述
在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。A先生现在要出门，所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。现在的问题是，他至少要拿多少只手套(左手加右手)，才能保证一定能选出一双颜色相同的手套。

给定颜色种数n(1≤n≤13),同时给定两个长度为n的数组left,right,分别代表每种颜色左右手手套的数量。数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。

测试样例：
4,[0,7,1,6],[1,5,0,6]
返回：10(解释：可以左手手套取2只，右手手套取8只)
 */
#include <iostream>
#include <vector>
using namespace std;
class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        // write code here
        int count = 0;
        int leftSum = 0;
        int rightSum = 0;
        int leftMin = 27;
        int rightMin = 27;
        for(int i = 0; i < n; i++)
        {
            //如果不存在这种颜色手套有一只不匹配则为无效解，这些手套必须全部拿上
            if(left[i] == 0 || right[i] == 0)
            {
                count += left[i];
                count += right[i];
            }
            else
            {
                leftSum += left[i];
                rightSum += right[i];
                leftMin = min(leftMin, left[i]);
                rightMin = min(rightMin, right[i]);
            }
        }
        //根据数学原理可知要把一只手所有颜色手套全拿完需要这只手所有颜色手套总和-最小值+1 
        return count + min(leftSum - leftMin + 1, rightSum - rightMin + 1) + 1;
    }
};
/**
 * class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        // write code Ahere
        int rightSum = 0;
        int leftSum = 0;
        int sum = 0;
        int leftMin = INT_MAX;
        int rightMin = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(left[i] == 0 || right[i] == 0)
            {
                sum = sum + left[i] + right[i];
            }
            else
            {
                rightSum += right[i];
                leftSum += left[i];
                rightMin = min(rightMin, right[i]);
                leftMin = min(leftMin, left[i]);
            }
        }
        return sum + min((rightSum - rightMin + 1), (leftSum - leftMin + 1)) + 1;
    }
};
 */