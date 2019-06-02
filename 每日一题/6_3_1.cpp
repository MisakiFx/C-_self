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