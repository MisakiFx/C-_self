#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int res = data[0];
        for(int i = 1; i < data.size(); i++)
        {
            res ^= data[i];
        }
        int index = 0;
        while(((res & 1) == 0) && index < 32)
        {
            index++;
            res = res >> 1;
        }
        *num1 = *num2 = 0;
        for(int i = 0; i < data.size(); i++)
        {
            int temp = data[i];
            temp = temp >> index;
            if(temp & 1 == 1)
            {
                *num1 ^= data[i];
            }
            else 
            {
                *num2 ^= data[i];
            }
        }
    }
};