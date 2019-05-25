//https://www.nowcoder.com/practice/eac8c671a0c345b38aa0c07aba40097b?tpId=85&&tqId=29866&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
/**
 * 题目描述
输入n个整数，输出出现次数大于等于数组长度一半的数。
输入描述:
每个测试输入包含 n个空格分割的n个整数，n不超过100，其中有一个整数出现次数大于等于n/2。
输出描述:
输出出现次数大于等于n/2的数。

示例1
输入
3 9 3 2 5 6 7 3 2 3 3 3

输出
3
 */
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    int hashTable[10] = {0};
    int count = 0;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            hashTable[str[i] - '0']++;
            count++;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        if(hashTable[i] >= count / 2)
        {
            cout << i;
            return 0;
        }
    }
}
*/
//另一种思想，用一个变量count记录读取每个变量变化的次数，一个变量temp记录可能过
//半的数，先让count=1，然后让temp=vec[0]，然后往后遍历一遍，碰到和temp相同的数就给count++，否
//则就count--，如果，count变成0，就让temp=vec[i](vec数组遍历过程中的当前值),并让count=1，如此遍历
//一遍，因为有一个数过半，所以temp最后肯定存储的是过半的数
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec;
    int n = 0;
    while(cin >> n)
    {
        vec.push_back(n);
    }
    int count = 1;
    int temp = vec[0];
    for(int i = 1; i < vec.size(); i++)
    {
        if(vec[i] == temp)
        {
            count++;
        }
        else
        {
            count--;
        }
        if(count == 0)
        {
            temp = vec[i];
            count = 1;
        }
    }
    cout << temp << endl;
}


