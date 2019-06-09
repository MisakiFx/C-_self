//https://www.nowcoder.com/practice/668603dc307e4ef4bb07bcd0615ea677?tpId=37&amp;&amp;tqId=21297&amp;rp=1&amp;ru
/**
 * 题目描述
在命令行输入如下命令：

xcopy /s c:\ d:\，

各个参数如下： 

参数1：命令字xcopy 

参数2：字符串/s

参数3：字符串c:\

参数4: 字符串d:\

请编写一个参数解析程序，实现将命令行各个参数解析出来。

解析规则： 
1.参数分隔符为空格 
2.对于用“”包含起来的参数，如果中间有空格，不能解析为多个参数。比如在命令行输入xcopy /s “C:\program files” “d:\”时，参数仍然是4个，第3个参数应该是字符串C:\program files，而不是C:\program，注意输出参数时，需要将“”去掉，引号不存在嵌套情况。
3.参数不定长 
4.输入由用例保证，不会出现不符合要求的输入 
输入描述:
输入一行字符串，可以有空格

输出描述:
输出参数个数，分解后的参数，每个参数都独占一行
示例1

输入
xcopy /s c:\\ d:\\

输出
4
xcopy
/s
c:\\
d:\\
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string str1;
    while(getline(cin, str1))
    {
        str1.push_back(' ');
        vector<string> argvs;
        string str2;
        for(int i = 0; i < str1.size(); i++)
        {
            if(str1[i] == '"')
            {
                i++;
                while(str1[i] != '"')
                {
                    i++;
                    str2 += str1[i];
                }
                if(str2.size() > 0)
                {
                    argvs.push_back(str2);
                    str2.resize(0);
                }
                continue;
            }
            if(str1[i] != ' ')
            {
                //不为空格拼接至字符串末尾
                str2 += str1[i];
            }
            if(str1[i] == ' ')
            {
                //为空格则将str2插入vector末尾，并将str2清空
                if(str2.size() > 0)
                {
                    argvs.push_back(str2);
                    str2.resize(0);
                }
            }
        }
        cout << argvs.size() << endl;
        for(int i = 0; i < argvs.size(); i++)
        {
            cout << argvs[i] << endl;
        }
    }
}