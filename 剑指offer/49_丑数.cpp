#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index <= 0)
        {
            return 0;
        }
        vector<int> res(index, 0);
        res[0] = 1;
        int indexOf2 = 0, indexOf3 = 0, indexOf5 = 0;
        int nextIndex = 1;
        while(nextIndex < index)
        {
            res[nextIndex] = min(min(res[indexOf2] * 2, res[indexOf3] * 3), res[indexOf5] * 5);
            while(res[indexOf2] * 2 <= res[nextIndex])
            {
                indexOf2++;
            }
            while(res[indexOf3] * 3 <= res[nextIndex])
            {
                indexOf3++;
            }
            while(res[indexOf5] * 5 <= res[nextIndex])
            {
                indexOf5++;
            }
            nextIndex++;
        }
        return res[index - 1];
    }
};
