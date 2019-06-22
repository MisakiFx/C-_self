//https://www.nowcoder.com/practice/181a1a71c7574266ad07f9739f791506?tpId=37&&tqId=21288&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
/**
 * 题目描述
查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
输入描述:
输入两个字符串
输出描述:
返回重复出现的字符

示例1
输入
abcdefghijklmnop
abcsafjklmnopqrstuvw

输出
jklmnop
 */
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//    string str1, str2;
//    while(cin >> str1 >> str2)
//    {
//        string maxString;
//        int i = 0;
//        if(str1.size() > str2.size())
//        {
//            swap(str1, str2);
//        }
//        for(int i = 0; i < str1.size(); i++)
//        {
//            for(int j = 0; j <= str2.size(); j++)
//            {
//                string curString;
//                if(str1[i] == str2[j] && str1[m] != '\0')
//                {
//                    int m = i;
//                    int n = j;
//                    while(str1[m] == str2[n])
//                    {
//                        curString += str1[m];
//                        m++;
//                        n++;
//                    }
//                    if(curString.size() > maxString.size())
//                    {
//                        maxString = curString;
//                    }
//                    curString.resize(0);
//                }
//            }
//        }
//        cout << maxString << endl;
//    }
//}
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string str1, str2;
    while(cin >> str1 >> str2)
    {
        if(str1.size() > str2.size())
        {
            swap(str1, str2);
        }
        int len1 = str1.size();
        int len2 = str2.size();
        vector<vector<int>> lens(len1 + 1, vector<int>(len2 + 1, 0));
        int maxlen = 0;
        int start = 0;
        for(int i = 1; i <= len1; i++)
        {
            for(int j = 1; j <= len2; j++)
            {
                if(str1[i - 1] == str2[j - 1])
                {
                    lens[i][j] = lens[i - 1][j - 1] + 1;
                }
                if(lens[i][j] > maxlen)
                {
                    maxlen = lens[i][j];
                    start = i - maxlen;
                }
            }
        }
        cout << str1.substr(start, maxlen) << endl;
    }
}