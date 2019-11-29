#include <iostream>
#include <string.h>

class Solution {
public:
    //判断是否存在一个有符号数字字符串
    bool ScanUnInt(const char** str)
    {
        const char* before = *str;
        while (**str != '\0' && **str >= '0' && **str <= '9')
        {
            (*str)++;
        }
        return *str > before;
    }
    //判断是否存在一个无符号数字字符串
    bool ScanInt(const char** str)
    {
        if(**str == '+' || **str == '-')
        {
            (*str)++;
        }
       return ScanUnInt(str);
    }
    bool isNumeric(const char* string)
    {
        if(string == nullptr || strlen(string) == 0)
        {
            return false;
        }
        bool isNumber = false;
        isNumber = ScanInt(&string);
        if(*string == '.')
        {
            string++;
            //这句一定要把调用放前面，因为如果先判断isNumber一旦为真调用就不执行了
            isNumber = ScanUnInt(&string) || isNumber;
        }
        if(*string == 'e' || *string == 'E')
        {
            string++;
            isNumber = isNumber && ScanInt(&string);
        }
        return isNumber && (*string == '\0');
    }

};
int main()
{
    Solution sol;
    std::cout << (sol.isNumeric("123.45e+6")) << std::endl;
}