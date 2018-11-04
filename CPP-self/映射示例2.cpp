#include <iostream>
#include <map>
#include <cctype>
using namespace std;
int main()
{
	map<char, int> s;//用于存放字母出现次数的映射
	char c;
	do
	{
		cin >> c;
		if(isalpha(c))
		{
			c = tolower(c);
			s[c]++;
		}
	}while(c != '.'); 
	for(map<char, int>::iterator iter = s.begin(); iter != s.end(); ++iter)
	{
		cout << iter->first << " " << iter->second << " ";
	}
	cout << endl;
}
