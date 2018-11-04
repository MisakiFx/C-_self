#include <iostream>
using namespace std;
//string类的用法已经说明
inline void test(const char *title, bool value)
{
	cout << title << " returns "
	<< (value ? "true" : "false") << endl;
} 
int main()
{
	string s1 = "DEF";
	cout << "s1 is" << s1 << endl;
	string s2;
	cout << "Please enter s2:";
	cin >> s2;
	cout << "length of s2:" << s2.length() << endl;
	test("s1 <= \"ABC\"",s1 <= "ABC");
	test("\"DEF\" <= s1","DEF" <= s1);
	s2 += s1;
	cout << "s2 = s2 + s1" << s2 << endl;
	cout << "length of s2:" << s2.length() << endl;
	/*getline函数*/
	fflush(stdin);
	string city,state;
	getline(cin,city,',');
	getline(cin,state);
	cout << "city:" << city << ',' << "state:" << state << endl;
}
