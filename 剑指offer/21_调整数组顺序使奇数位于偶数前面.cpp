#include <iostream>
#include <vector>
class Solution {
public:
    void reOrderArray(std::vector<int> &array) {
        std::vector<int> odd, even;
        for(const auto& e : array)
        {
            if(e % 2 == 0)
            {
                even.push_back(e);
            }
            else 
            {
                odd.push_back(e);
            }
        }
        for(const auto& e : even)
        {
            odd.push_back(e);
        }
        array = odd;
    }
};