#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;
template <class T>
class Array
{
	public:
		Array(int sz = 50);
		Array(const Array<T> &a);
		~Array();
		Array<T> & operator = (const Array<T> &rhs);
		T & operator [] (int i);
		const T & operator [] (int i) const;
		operator T * ();
		operator const T * () const;
		int getSize() const;//ȡ�����С 
		void resize(int sz);//�����޸������С 
	private:
		T* list;//���ڴ�Ŷ�̬����������ڴ��׵�ַ
		int size;//�����С 
};
template <class T>
Array<T>::Array(int sz)
{
	assert(sz >= 0);//szΪ�����С��Ӧ���Ǹ�
	size = sz;
	list = new T [size]; 
}
template <class T>
Array<T>::~Array()
{
	delete[] list;
}
template <class T>
Array<T>::Array(const Array<T> &a)
{
	size = a.size;
	list = new T [size];
	for(int i = 0; i < size; i++)
	{
		list[i] = a.list[i];
	}
}
template <class T>
Array<T> & Array<T>::operator = (const Array<T> &rhs)
{
	if(&rhs != this)
	{
		if(size != rhs.size)
		{
			delete[] list;
			size = rhs.size;
			list = new T[size];
		}
		for(int i = 0; i < size; i++)
		{
			list[i] = rhs.list[i];
		}
	}
	return *this;//���ص�ǰ��������� 
}
template <class T>
T & Array<T>::operator [] (int n)
{
	assert(n >= 0 && n < size);
	return list[n];
}
template <class T>
const T & Array<T>::operator [] (int n) const
{
	assert(n >= 0 && n < size);
	return list[n];
}
template <class T>
Array<T>::operator T * ()//����ָ��ת����������޷���ֵ�����������Ϊ  ����* 
{
	return list;//���ص�ǰ������˽��������׵�ַ 
}
template <class T>
int Array<T>::getSize() const
{
	return size;
}
template <class T>
void Array<T>::resize(int sz)
{
	assert(sz >= 0);
	if(sz == size)
		return;
	T* newList = new T[sz];
	int n = (sz < size) ? sz : size;
	for(int i = 0; i < n; i++)
	{
		newList[i] = list[i];
	}
	delete[] list;
	list = newList;
	size = sz;
}
int main()
{
	Array<int> a(10);
	int n, count = 0;
	cout << "Enter a value >= 2 as upper limit for prime numbers:";
	cin >> n;
	for(int i = 2; i < n; i++)
	{
		bool isPrime = true;
		for(int j = 0; j < count; j++)
		{
			if(i % a[j] == 0)
			{
				isPrime = false;
				break;
			}
		}
		if(isPrime)
		{
			if(count == a.getSize())
			{
				a.resize(count * 2);
			}
			a[count++] = i;
		}
	}
	for(int i = 0; i < count; i++)
	{
		cout << setw(8) << a[i];
	}
	cout << endl;
}
