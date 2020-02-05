#include <iostream>
#include <string>
#include <vector>

//利用动态规划的思想从后往前解决问题
int GetTranslationCount(const std::string& number)
{
    int length = number.size();
    std::vector<int> counts(length);
    for(int i = length - 1; i >= 0; i--)
    {
        int count = 0;
        //先按单一数字进行计算
        if(i < length - 1)
        {
            count = counts[i + 1];
        }
        else 
        {
            count = 1;
        }
        //从倒数第二位起要开始考虑计算两位数字转换的情况
        if(i < length - 1)
        {
            int num = (number[i] - '0') * 10 + (number[i + 1] - '0');
            //如果合法则计算应该加上的次数
            if(num <= 25)
            {
                if(i < length - 2)
                {
                    count += counts[i + 2];
                }
                else 
                {
                    count += 1;
                }
            }
        }
        counts[i] = count;
    }
    return counts[0];
}
int GetTranslationCount(int number)
{
    if(number < 0)
    {
        return 0;
    }
    std::string strNumber = std::to_string(number);
    return GetTranslationCount(strNumber);
}


int main()
{
    std::cout << GetTranslationCount(12258) << std::endl;
}