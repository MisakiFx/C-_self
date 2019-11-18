#include <iostream>
#include <math.h>
class Solution {
public:
    /*
    double PowerWithExponent(double base, int exponent)
    {
        double result = 1.0;
        for(int i = 0; i < exponent; i++)
        {
            result *= base;
        }
        return result;
    }
    */
   //递归来做乘方，效率由ON -> OlogN
   //2 ^ 32 = (2 ^ 16) ^ 2 = ((2 ^ 8) ^ 2) ^ 2 = ....
    double PowerWithExponent(double base, int exponent)
    {
        if(exponent == 0)
        {
            return 1;
        }
        if(exponent == 1)
        {
            return base;
        }
        double result = PowerWithExponent(base, exponent >> 1);
        result *= result;
        //奇数次方
        if(exponent & 0x1 == 1)
        {
            result *= base;
        }
        return result;
    }
    double Power(double base, int exponent) {
        if((base - 0.0) <= 1e-5 && exponent < 0)
        {
            return 0;
        }
        int absExponent = abs(exponent);
        double result = PowerWithExponent(base, absExponent);
        std::cout << result << std::endl;
        if(exponent < 0)
        {
            result = 1.0 / result;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    double res = sol.Power(2, 3);
    std::cout << res << std::endl;
}