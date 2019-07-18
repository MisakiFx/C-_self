#include <iostream>
#include <string>
using namespace std;

//// ʵ��һ�������String -> ��ͳд��
////class String
////{
////public:
////	String(const char* str = "")
////	{
////		_str = new char[strlen(str) + 1];
////		strcpy(_str, str);
////	}
////
////	// s2(s1)
////	String(const String& s)
////	{
////		_str = new char[strlen(s._str) + 1];
////		strcpy(_str, s._str);
////	}
////
////	// s1 = s2
////	String& operator=(const String& s)
////	{
////		if (this != &s)
////		{
////			delete[] _str;
////			_str = new char[strlen(s._str) + 1];
////			strcpy(_str, s._str);
////		}
////
////		return *this;
////	}
////
////	~String()
////	{
////		if (_str)
////		{
////			delete[] _str;
////			_str = nullptr;
////		}
////	}
////
////private:
////	char* _str;
////};
////
////int main()
////{
////	return 0;
////}
//
////// �ִ�д��
////class String
////{
////public:
////	String(const char* str = "")
////	{
////		_str = new char[strlen(str) + 1];
////		strcpy(_str, str);
////	}
////
////	// s2(s1)
////	String(const String& s)
////		:_str(nullptr)
////	{
////		String tmp(s._str);
////		swap(_str, tmp._str);
////	}
////
////	// s1 = s3
////	String& operator=(String s)
////	{
////		swap(_str, s._str);
////
////		return *this;
////	}
////
////
////	// s1 = s3
////	//String& operator=(const String& s)
////	//{
////	//	if (this != &s)
////	//	{
////	//		String tmp(s); //String tmp(s._str);
////	//		swap(_str, tmp._str);
////	//	}
////
////	//	return *this;
////	//}
////
////
////
////	~String()
////	{
////		if (_str)
////		{
////			delete[] _str;
////			_str = nullptr;
////		}
////	}
////
////	char* c_str()
////	{
////		return _str;
////	}
////
////private:
////	char* _str;
////};
////
////int main()
////{
////	String s1("hello");
////	String s2(s1);
////
////	cout << s1.c_str() << endl;
////	cout << s2.c_str() << endl;
////
////	String s3("world");
////	s1 = s3;
////	cout << s1.c_str() << endl;
////
////	return 0;
////}
//
//#include "String.h"
//
//void Test1()
//{
//	String s1("hello");
//	String s2(s1);
//
//	cout << s1.c_str() << endl;
//	cout << s2.c_str() << endl;
//
//	String s3("world");
//	s1 = s3;
//	cout << s1.c_str() << endl;
//}
//
//void Test2()
//{
//	String s1("hello");
//	for (size_t i = 0; i < s1.Size(); ++i)
//	{
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//
//	String::iterator it1 = s1.begin();
//	while (it1 != s1.end())
//	{
//		cout << *it1 << " ";
//		++it1;
//	}
//	cout << endl;
//
//	const String s2("world");
//	String::const_iterator it2 = s2.begin();
//	while (it2 != s2.end())
//	{
//		//*it2 = 'x';
//		cout << *it2 << " ";
//		++it2;
//	}
//	cout << endl;
//	cout << s2.c_str() << endl;
//
//	for (auto &e : s1)
//	{
//		e = 'y';
//		cout << e << " ";
//	}
//	cout << endl;
//	cout << s1.c_str() << endl;
//}
//
//void Test3()
//{
//	String s1("hello");
//	s1 += ' ';
//	s1 += "world";
//	cout << s1.c_str() << endl;
//	cout << s1.Size() << endl;
//	cout << s1.Capacity() << endl;
//
//	s1.Resize(5);
//	cout << s1.c_str() << endl;
//	cout << s1.Size() << endl;
//	cout << s1.Capacity() << endl;
//
//	s1.Resize(20, 'x');
//	cout << s1.c_str() << endl;
//	cout << s1.Size() << endl;
//	cout << s1.Capacity() << endl;
//}
//
//void Test4()
//{
//	String s1("hello!!!!!!");
//	s1.Insert(5, " world world world");
//	cout << s1.Size() << endl;
//	cout << s1.Capacity() << endl;
//	cout << s1.c_str() << endl;
//
//	s1.Insert(0, "hello ");
//	cout << s1.c_str() << endl;
//
//	s1.Erase(0, 6);
//	cout << s1.c_str() << endl;
//	s1.Erase(5, 1000);
//	cout << s1.c_str() << endl;
//	s1.Erase(2, 3);
//	cout << s1.c_str() << endl;
//}
//
//void Test5()
//{
//	String url("http://www.cplusplus.com//reference/cstring/strstr/?kw=strstr");
//	cout << url.Find("www") << endl;
//	cout << url.Find("//", 7) << endl;
//
//	String s1("hello");
//	String s2("hello!");
//	String s3("hello");
//
//	cout << (s1 < s2) << endl;
//	cout << (s1 < s3) << endl;
//	cout << (s1 == s2) << endl;
//	cout << (s1 == s3) << endl;
//}
//
//#include <windows.h>
//
////void FindFile(const std::basic_string<wchar_t> strPath)
////{
////	WIN32_FIND_DATA findData = {0};
////	wstring strFindPath = strPath + L"\\*.*";
////	//���ҵ�һ���ļ�
////	HANDLE hFindFine = FindFirstFile(strFindPath.c_str(), &findData);
////	if (INVALID_HANDLE_VALUE == hFindFine)
////		printf("Error:%d", GetLastError());
////	//ѭ���ݹ�����ļ�
////	do
////	{
////		//�жϸ��ļ��Ƿ�Ϊ�ļ���
////		if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
////		{
////			if (findData.cFileName[0] == '.')
////				continue;
////
////			cout << findData.cFileName << endl;
////
////			//�����ļ����ļ��У���ݹ���в��Ҹ��ļ����µ��ļ�
////			//FindFile(strNeedFindPaht);
////		}
////		else
////		{
////			//cout << "��" << strPath << "�ҵ��ļ�:\t" << findData.cFileName << endl;
////		}
////	} while (FindNextFile(hFindFine, &findData));
////	//�ر��ļ��������
////	FindClose(hFindFine);
////}

int main()
{
	string str = "123456";//���ι������ʽ����ת�� + ��������
	for(int i = 0; i < str.size(); i++)//size()ȡ������
	{
		cout << str[i] << " ";//operator[]���ص�����
	}
	cout << endl;
	str.append("abc");//append()�ӿ�
	str.push_back('d');//push_back�ӿ�ʹ��
	str += "efg";//operator += ����ʹ��
	//��������Ӧ��
	string::iterator it = str.begin();
	while(it != str.end())
	{
		cout << * it << " ";
		it++;
	}
}