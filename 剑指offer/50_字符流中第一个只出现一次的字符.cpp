#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution
{
public:
  //Insert one char from stringstream
    Solution()
        :_index(0)
        ,_occurance(256, -1)
    {
        
    }
    void Insert(char ch)
    {
        if(_occurance[ch] == -1)
        {
            _occurance[ch] = _index;
        }
        else if(_occurance[ch] >= 0)
        {
            _occurance[ch] = -2;
        }
        _index++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int minIndex = numeric_limits<int>::max();
        char ch = 0;
        for(int i = 0; i < _occurance.size(); i++)
        {
            if(_occurance[i] >= 0 && _occurance[i] < minIndex)
            {
                ch = (char)i;
                minIndex = _occurance[i];
            }
        }
        if(minIndex == numeric_limits<int>::max())
        {
            return '#';
        }
        return ch;
    }
    int _index;
    vector<int> _occurance;
};