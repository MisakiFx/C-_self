#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
char Reverse(char a)
{
    switch(a)
    {
        case 'A':
        case 'B':
        case 'C':
            return '2';
            break;
        case 'D':
        case 'E':
        case 'F':
            return '3';
            break;
        case 'G':
        case 'H':
        case 'I':
            return '4';
            break;
        case 'J':
        case 'K':
        case 'L':
            return '5';
            break;
        case 'M':
        case 'N':
        case 'O':
            return '6';
            break;
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
            return '7';
            break;
        case 'T':
        case 'U':
        case 'V':
            return '8';
            break;
        case 'W':
        case 'X':
        case 'Y':
        case 'z':
            return '9';
            break;
        default:
            return '0';
            break;
    }
}
int main()
{
    int num;
    while(cin >> num)
    {
        set<string> result;
        for(int i = 0; i < num; i++)
        {
            string str;
            cin >> str;
            //将字符串进行转换
            for(int j = 0; j < str.size(); j++)
            {
                if(str[j] >= '0' && str[j] <= '9')
                {
                    continue;
                }
                else if(str[j] == '-')
                {
                    str.erase(j, 1);
                    j--;
                }
                else
                {
                    char c = Reverse(str[j]);
                    str[j] = c;
                }
            }
            //存入二叉排序树进行排序并且去重
            str.insert(3, "-");
            result.insert(str);
        }
        set<string>::iterator it = result.begin();
        while(it != result.end())
        {
            cout << *it << endl;
            it++;
        }
    }
}