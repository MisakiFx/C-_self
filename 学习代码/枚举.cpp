#include <stdio.h>
enum ETest//整数常量的定义,，枚举定义，自动向下生成不重复的常量 
{
	READ_ONLY = 1,
	HIDE,
	SYSTEM,
}; 
int main()
{
	int i = HIDE;
	int j = SYSTEM;
	printf("i = %d\n",HIDE);
	printf("j = %d\n",SYSTEM);
	ETest t = HIDE;//使用枚举定义一个常量，常量值只能是枚举内容中的一个，做参数时也一样，只能是枚举内容的一个
} 
