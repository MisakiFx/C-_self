#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> count;
        for(const auto& e : str)
        {
            count[e]++;
        }
        for(int i = 0; i < str.size(); i++)
        {
            if(count[str[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};