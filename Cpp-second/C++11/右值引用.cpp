#include <iostream>
#include <string.h>

//实现一个简单的string类
class String
{
	friend std::ostream& operator<<(std::ostream& out, const String& str);
public:
	String(const char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
		std::cout << "String(char* str = )" << std::endl;
	}
	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
		std::cout << "String(const String& s)" << std::endl;
	}
	//移动构造
	String(String&& s)
		:_str(s._str)
	{
		s._str = nullptr;//这里一定要记着将将亡值的原本指针置空，否则会把我们拿来用的资源释放了
		std::cout << "String(String&& s)" << std::endl;
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* temp = _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
			delete[] temp;
		}
		return *this;
	}
	//移动赋值
	String& operator=(String&& s)
	{
		if (this != &s)
		{
			char* temp = _str;
			_str = s._str;
			s._str = temp;
			std::cout << "String& operator=(String&&)" << std::endl;
		}
		return *this;
	}
	~String()
	{
		delete[] _str;
	}
private:
	char* _str;
};
std::ostream& operator<<(std::ostream& out, const String& str)
{
	out << str._str;
	return out;
}
String getString(const char* str)
{
	String temp(str);
	return temp;
}
void test()
{
	String str = getString("Misaki");
	str = String("misaki");
	std::cout << str << std::endl;
}
int main()
{
	test();
}