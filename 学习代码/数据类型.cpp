#include <iostream>
#include <climits>//c限制头文件 
using namespace std;
int main()
{
	//打印int类型的最大值(有符号)
	cout << INT_MAX << endl;
	//打印int的最小值(有符号)
	cout << INT_MIN << endl; 
	size_t abc = 19;
	cout << abc << endl;
	typedef char wode_char;//定义类型的别名。将wode_char定义为char数据类型 
	wode_char name = 'a';
	cout << name << endl;
}
