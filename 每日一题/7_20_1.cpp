#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>
using namespace std;
class MaxGap {
public:
    int findMaxGap(vector<int> A, int n) {
        // write code here
        int absMax = 0;
        for(int i = 0; i < n - 1; i++)
        {
            vector<int>::iterator it = A.begin();
            for(int j = 0; j < i; j++)
            {
                ++it;
            }
            vector<int> pre(A.begin(), it + 1);
            vector<int> suf(it + 1, A.end());
            int max1= INT_MIN;
            int max2 = INT_MIN;
            for(int j = 0; j < pre.size(); j++)
            {
                if(pre[j] > max1)
                {
                    max1 = pre[j];
                }
            }
            for(int j = 0; j < suf.size(); j++)
            {
                if(suf[j] > max2)
                {
                    max2 = suf[j];
                }
            }
            int result = abs(max1 - max2);
            if(result > absMax)
            {
                absMax = result;
            }
        }
        return absMax;
    }
};
int main()
{
    MaxGap max;
    vector<int> arr = {15, 30, 61, 99};
    int maxNum = max.findMaxGap(arr, 4);
    cout << maxNum << endl;
}