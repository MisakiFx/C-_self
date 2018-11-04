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
T Stack<T, SIZE>::pop()//����ջ���� 
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
		Stack<double> s;// ������ջ 
		void enter(double num);//��������Numѹ��ջ
		bool getTwoOperands(double &opnd1, double &opnd2);//��������������������ջ������opnd1��opnd2�� 
		void computer(char op);//ִ���ɲ�����ŷ��ָ��������
	public:
		void run();//���м���������
		void clear();//��ղ�����ջ 
};
inline double stringToDouble(const string &str)//���ߺ��������ڽ��ַ���ת��Ϊʵ�� 
{
	istringstream stream(str);//�ַ���������
	double result;
	stream >> result;
	return result; 
}
void Calculator::enter(double num)//��������Numѹ��ջ 
{
	s.push(num);
}
bool Calculator::getTwoOperands(double &opnd1, double &opnd2)
{
	if(s.isEmpty())//���ջ�Ƿ�Ϊ�� 
	{
		cerr << "Missing operand!" << endl;
		return false;
	}
	opnd1 = s.pop();//���Ҳ���������ջ
	if(s.isEmpty())
	{
		cerr << "Missing operand!" << endl;
		return false;
	}
	opnd2 = s.pop();//�������������ջ 
	return true;
} 
void Calculator::computer(char op)
{
	double operand1, operand2;
	bool result = getTwoOperands(operand1, operand2);
	if(result)//����ɹ� 
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
					s.clear();//���ջ 
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
		s.clear();//���������������ջ 
}
void Calculator::run()//���벢�����׺���ʽ 
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
				if(str.size() > 1)//�ж��Ǹ��Ż��Ǽ��� 
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
