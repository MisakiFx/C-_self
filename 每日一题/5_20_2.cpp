/*
https://www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212?tpId=85&&tqId=29868&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking


题目描述
输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
输入描述:
每个测试输入包含2个字符串
输出描述:
输出删除后的字符串


示例1

输入
They are students. aeiou

输出
Thy r stdnts.

*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
  string str1, str2;
  getline(std::cin, str1);
  getline(std::cin, str2);
  string::iterator it = str2.begin();
  while(it != str2.end())
  {
    for(int i = 0; i < str1.size(); i++)
    {
      if(str1[i] == *it)
      {
        str1.erase(i, 1);
      }
    }
    ++it;
  }
  cout << str1 << endl;
}
