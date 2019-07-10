// write your code here cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1, str2;
    while(cin >> str1 >> str2)
    {
        int cur = 0;//当前准备开始找的地方
        int num = 0;
        while(cur < str1.size())
        {
            int result = str1.find(str2, cur);
            if(result == -1)
            {
                break;
            }
            cur = result + str2.size();
            num++;
        }
        cout << num << endl;
    }
}