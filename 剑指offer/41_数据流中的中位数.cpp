#include <iostream>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    void Insert(int num)
    {
        if(((_max.size() + _min.size()) & 1) == 0)//数据总量为偶数，放到小根堆
        {
            if(_max.size() > 0 && num < _max.top())
            {
                _max.push(num);
                num = _max.top();
                _max.pop();
            }
            _min.push(num);
        }
        else //数据总量为奇数，放到大根堆
        {
            if(_min.size() > 0 && num > _min.top())
            {
                _min.push(num);
                num = _min.top();
                _min.pop();
            }
            _max.push(num);
        }
    }
    double GetMedian()
    { 
        int size = _min.size() + _max.size();
        if(size == 0)
        {
            return -1;
        }
        double mid = 0;
        if((size & 1) == 1)
        {
            mid = _min.top();
        }
        else 
        {
            mid = ((double)_min.top() + _max.top()) / 2;
        }
        return mid;
    }
private:
    priority_queue<int> _max;
    priority_queue<int, vector<int>, greater<int>> _min;
};