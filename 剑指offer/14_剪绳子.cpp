#include <iostream>
//动态规划问题，要从小问题逐步往大问题开始求解，大问题的解往往依赖于子问题的解
//还是确定初始状态，确定中间状态，拿到最终状态即可
class Solution {
public:
    int cutRope(int number) {
        //特殊情况特殊处理
        if(number < 2)
        {
            return 0;
        }
        if(number == 2)
        {
            return 1;
        }
        if(number == 3)
        {
            return 2;
        }
        int* arr = new int[number + 1];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 3;
        int m = 0;
        //这里开始从长度为4的绳子进行动规，长度为4的绳子依赖于前面的子问题f(1)和f(2)，
        //在递归时除去特殊情况后，1, 2, 3全部认为他们的解就是1, 2, 3,这是初始状态。
        for(int i = 4; i <= number; i++)
        {
            m = 0;
            for(int j = 0; j <= i / 2; j++)
            {
                int mul = arr[j] * arr[number - j];
                if(mul > m)
                {
                    m = mul;
                }
            }
            arr[i] = m;
        }
        m = arr[number];
        delete[] arr;
        return m;
    }
};