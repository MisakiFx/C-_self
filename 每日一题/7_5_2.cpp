//数学递推的递推公式，或者找规律的答案
//https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c
/**
*
居然有假币！ 现在猪肉涨了，但是农民的工资却不见涨啊，没钱怎么买猪肉啊。nowcoder这就去买猪肉，结果找来的零钱中有假币！！！可惜nowcoder 一不小心把它混进了一堆真币里面去了。只知道假币的重量比真币的质量要轻，给你一个天平（天平两端能容纳无限个硬币），请用最快的时间把那个可恶的假币找出来。

输入描述:
1≤n≤2^30,输入0结束程序。

输出描述:
最多要称几次一定能把那个假币找出来？
示例1
输入
3
12
0
输出
1
3
 */
//#include <iostream>
//using namespace std;
//int main()
//{
//    int n;
//    while(cin >> n)
//    {
//        if(n == 0)
//        {
//            break;
//        }
//        int count = 0;
//        uint64_t sum = 1;
//        while(sum < n)
//        {
//            sum *= 3;
//            count++;
//        }
//        cout << count << endl;
//    }
//}
// write your code here cpp
#include <iostream>
using namespace std;
int main()
{
    long long num;
    while(cin >> num && num != 0)
    {
        int count = 0;
        while(num >= 2)
        {
            if(num % 3 != 0)
            {
                num = num / 3 + 1;
            }
            else
            {
                num = num / 3;
            }
            count++;
        }
        cout << count << endl;
    }
}