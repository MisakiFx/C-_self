#include <stdio.h>
//能用循环不用递归，递归用于二叉树 
int Test(int n)
{
	if(n == 0)//当n为0时栈不断退出知道退出到第一个栈再返回主函数 
	{
		return 0;
	} //递归必须有结束条件，满足条件循环结束 
	return Test(n - 1);//每次调用都在不停往下压栈 
 } 
int main()
{
	int n = Test(10);
	return 0;
 } 
