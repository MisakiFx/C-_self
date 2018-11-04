#include <iostream>
using namespace std;
//枚举类：强类型枚举
//enum class 枚举类型名:底层类型(默认int类型) ｛枚举值列表｝;
/*
1、强作用域
2、转换限制
3、可以指定底层类型 
*/
enum class Type 
{
	General, 
	Lisght,
	Medium, 
	Heavy
};
enum class Type2:char 
{
	General = 1,
	Light,
	Medium,
	Heavy
}; 
enum class Side
{
	Right,
	Left
};
 enum class Thing
{
	Wrong,
	Right 	
}; 
int main()
{
	Side s = Side::Right;
	Thing w = Thing::Wrong;
	cout << (s == w) << endl;//无法直接比较不同枚举类
	return 0; 
}
