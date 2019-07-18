#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int, int> count;
        for(int i = 0; i < numbers.size(); i++)
        {
            count[numbers[i]]++;
        }
        map<int, int>::iterator it = count.begin();
        while(it != count.end())
        {
            if(it->second > (numbers.size() / 2))
            {
                return it->first;
            }
            it++;
        }
        return 0;
    }
};