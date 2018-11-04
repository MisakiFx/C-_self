#include <iostream>
//命名空间：为了防止不同文件中函数出现相同名字，使用不同的命名空间进行命名
using namespace std;//使用标准输入输出命名空间 
namespace M
{
	bool IsDierectory()
	{
		return true;
	}
	bool IsHiden()
	{
		return false;
	}
} 
namespace ZHANG
{
	bool IsDierectory()
	{
		return true;
	}
	bool IsHiden()
	{
		return false;
	}
}
bool IsDierectory()//全局函数 
{
	return true;
}
//using namespace M;//默认使用M的命名空间 
int main()
{
	double i = 20;
	bool b = M::IsDierectory();//调用M命名空间内的函数
	bool a = ZHANG::IsDierectory();//调用ZHANG命名空间内的函数
	bool c = ::IsDierectory();//在用using namespace 后默认调用M内的命名空间
	std::cout << "sizeof(i) = " << sizeof(i) << std::endl;
} 
