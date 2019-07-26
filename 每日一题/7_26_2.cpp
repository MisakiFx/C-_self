// write your code here cpp
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int num = 0;
    while(cin >> num)
    {
        stack<int> nums;
        for(int i = 0; i < num; i++)
        {
            //这里要用string因为操作数可能有很多位
            string ch;
            cin >> ch;
            if(ch[0] >= '0' && ch[0] <= '9')
            {
                nums.push(atoi(ch.c_str()));
            }
            else
            {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                int res = 0;
                if(ch[0] == '+')
                {
                    res = num2 + num1;
                }
                else if(ch[0] == '-')
                {
                    res = num2 - num1;
                }
                else if(ch[0] == '*')
                {
                    res = num2 * num1;
                }
                else if(ch[0] == '/')
                {
                    res = num2 / num1;
                }
                nums.push(res);
            }
        }
        cout << nums.top() << endl;
    }
    
}