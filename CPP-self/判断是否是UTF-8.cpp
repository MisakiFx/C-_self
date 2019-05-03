#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int size = data.size();
        for(int i = 0; i < size; i++)
        {
            int bitCount = 0;
            for(int j = 7; j > 0; j--)
            {
                if(((data[i] >> j) % 2) == 0)
                {
                    break;
                }
                bitCount++;
            }
            if(bitCount == 1 || bitCount > 4)
            {
                return false;
            }
            if(bitCount + i > size)
            {
                return false;
            }
            for(int j = 0; j < bitCount - 1; j++)
            {
                if(((data[i + j + 1] >> 7) % 2) == 0 || ((data[i + j + 1] >> 6) % 2) != 0)
                {
                    return false;
                }
            }
            if(bitCount != 0)
            {
                i += bitCount - 1;
            }
        }
        return true;
    }
};
int main()
{
    Solution sol;
    vector<int> data = {197, 130, 1}; 
    bool isTrue = sol.validUtf8(data);
    cout << isTrue << endl;
}