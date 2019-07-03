//但是傻逼牛客不给过
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     *  奇数位上都是奇数或者偶数位上都是偶数
     *  输入：数组arr，长度大于2
     *  len：arr的长度
     *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
     */
    void oddInOddEvenInEven(vector<int>& arr, int len) 
    {
        //思路：i指向偶数位，j指向奇数位，由于不清楚其中有多少偶数和奇数，因此我们要两边同时进行判断
        //只要奇数位全为奇数，偶数位全为偶数就都可以终止循环
        //如果发生当前所指奇数位为偶数，并且当前所指偶数位为偶数则进行交换
        //如果当前奇数位为奇数则指向朝后移动
        //如果当前偶数位为偶数则指向朝后移动
        int i = 0, j = 1;
        while(i < len && j < len)
        {
            if(arr[i] % 2 != 0 && arr[j] % 2 == 0)
            {
                swap(arr[i], arr[j]);
            }
            if(arr[i] % 2 == 0)
            {
                i += 2;
            }
            if(arr[j] % 2 != 0)
            {
                j += 2;
            }
        }
    }
};
int main()
{

}