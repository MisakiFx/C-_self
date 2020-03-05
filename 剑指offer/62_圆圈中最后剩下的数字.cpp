#include <iostream>
#include <list>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1 || m < 1)
        {
            return -1;
        }
        std::list<int> l;
        for(int i = 0; i < n; i++)
        {
            l.push_back(i);
        }
        std::list<int>::iterator it = l.begin();
        while(l.size() > 1)
        {
            for(int i = 1; i < m; i++)
            {
                it++;
                if(it == l.end())
                {
                    it = l.begin();
                }
            }
            it = l.erase(it);
            if(it == l.end())
            {
                it = l.begin();
            }
        }
        return l.front();
    }
};