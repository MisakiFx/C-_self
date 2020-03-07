#include <iostream>

class Solution {
public:
    int Add(int num1, int num2)
    {
        int res = num1 ^ num2;
        int carry = num1 & num2;
        while(carry)
        {
            carry <<= 1;
            int temp = res;
            res = res ^ carry;
            carry = temp & carry;
        }
        return res;
    }
};
