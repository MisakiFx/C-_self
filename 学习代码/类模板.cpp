#include <iostream>
using namespace std;
//类模板 
class Student 
{
	private:
		int id;//学号 
		float gpa;//平均分 
	public:
		Student();
		Student(int id, float gpa);
		friend ostream &operator << (ostream &out, const Student student);
};
Student::Student()
{
	
}
Student::Student(int id, float gpa): id(id), gpa(gpa)
{
	
}
ostream &operator << (ostream &out, const Student student)
{
	cout << student.id << " " << student.gpa << endl;
}
template <class T>
class Store
{
	private:
		T item; //用于存放任意数据类型的数据
		bool haveValue;//用于标记item是否已经被存入内容 
	public:
		Store();
		T &getElem();//提取数据函数
		void putElem(const T &x);//存入数据函数 
}; 
//将函数在类外实现
template <class T>
Store<T>::Store(): haveValue(false)
{
	
}
template <class T>
T &Store<T>::getElem()
{
	if(haveValue == false)
	{
		cout << "No item present!" << endl;
		exit(1);//程序完全退出 
	}
	return item;
}
template <class T>
void Store<T>::putElem(const T &x)
{
	haveValue = true;
	item = x;
} 
int main()
{
	Store<int> s1, s2;
	s1.putElem(3);
	s2.putElem(-7);
	cout << s1.getElem() << " " << s2.getElem() << endl;
	Student g(1000, 10);
	Store<Student> s3;
	s3.putElem(g);
	cout << "The student id is " << s3.getElem() << endl;
	Store<double> d;
	cout << "Retrieving object D...";
	cout << d.getElem() << endl;
	//d未初始化，程序终止 
}
