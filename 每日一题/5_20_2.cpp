//在第一个字符串中删除第二个字符串中所有字符
//输出第一个字符串
#include <iostream>
#include <string>
using namespace std;
int main()
{
  string str1, str2;
  getline(std::cin, str1);k
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
