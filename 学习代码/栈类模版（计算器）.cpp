#include <iostream>
#include <cassert>
#include <sstream>
#include <cmath>
using namespace std;
template <class T, int SIZE = 50>
class Stack
{
	private:
		T list[SIZE];
		int top;
	public:
		Stack();
		void push(const T &item);
		T pop();
		void clear();
		const T &peek() const;
		bool isEmpty() const;
		bool isFull() const;
};
template <class T, int SIZE>
Stack<T, SIZE>::Stack(): top(-1)
{
	
}
template <class T, int SIZE>
void Stack<T, SIZE>::push(const T &item)
{
	assert(!isFull());
	list[++top] = item;
}
template <class T, int SIZE>
T Stack<T, SIZE>::pop()//弹出栈函数 
{
	assert(!isEmpty());
	return list[top--];
}
template <class T, int SIZE>
const T &Stack<T, SIZE>::peek() const
{
	assert(!isEmpty());
	return list[top];
}
template <class T, int SIZE>
bool Stack<T, SIZE>::isEmpty() const
{
	return top == -1;
}
template <class T, int SIZE>
bool Stack<T, SIZE>::isFull() const
{
	return top == SIZE - 1;
}
template <class T, int SIZE>
void Stack<T, SIZE>:: clear()
{
	top = -1;
}
class Calculator
{
	private:
		Stack<double> s;// 操作数栈 
		void enter(double num);//将操作数Num压入栈
		bool getTwoOperands(double &opnd1, double &opnd2);//连续将两个操作数弹出栈，放在opnd1和opnd2中 
		void computer(char op);//执行由操作符欧赔指定的运算
	public:
		void run();//运行计算器程序
		void clear();//清空操作数栈 
};
inline double stringToDouble(const string &str)//工具函数，用于将字符串转换为实数 
{
	istringstream stream(str);//字符串输入流
	double result;
	stream >> result;
	return result; 
}
void Calculator::enter(double num)//将操作数Num压入栈 
{
	s.push(num);
}
bool Calculator::getTwoOperands(double &opnd1, double &opnd2)
{
	if(s.isEmpty())//检查栈是否为空 
	{
		cerr << "Missing operand!" << endl;
		return false;
	}
	opnd1 = s.pop();//将右操作数弹出栈
	if(s.isEmpty())
	{
		cerr << "Missing operand!" << endl;
		return false;
	}
	opnd2 = s.pop();//将左操作数弹出栈 
	return true;
} 
void Calculator::computer(char op)
{
	double operand1, operand2;
	bool result = getTwoOperands(operand1, operand2);
	if(result)//如果成功 
	{
		switch(op)
		{
			case '+':
				s.push(operand2 + operand1);
				break;
			case '-':
				s.push(operand2 - operand1);
				break;
			case '*':
				s.push(operand2 * operand1);
				break;
			case '/':
				if(operand1 == 0)
				{
					cerr << "Divided by 0!" << endl;
					s.clear();//清空栈 
				}
				else
				{
					s.push(operand2 / operand1);
				}
				break;
			case '^':
				s.push(pow(operand2, operand1));
				break;
			default:
				cerr << "Unrecognized operator!" << endl;
				break;
		}
		cout << " = " << s.peek() << " ";
	}
	else
		s.clear();//操作数不够，清空栈 
}
void Calculator::run()//读入并处理后缀表达式 
{
	string str;
	while(cin >> str, str != "q");
	{
		switch(str[0])
		{
			case 'c':
				s.clear();
				break;
			case '-':
				if(str.size() > 1)//判断是负号还是减号 
					enter(stringToDouble(str));
				else
					computer(str[0]);
				break;
			case '+':
			case '*':
			case '/':
			case '^':
				computer(str[0]);
			default:
				enter(stringToDouble(str));
				break;
		}
	}
}
void Calculator::clear()
{
	s.clear();
}
int main()
{
	Calculator c;
	c.run();
}
