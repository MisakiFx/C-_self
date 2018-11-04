#include <iostream>
using namespace std;
//��ģ�� 
class Student 
{
	private:
		int id;//ѧ�� 
		float gpa;//ƽ���� 
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
		T item; //���ڴ�������������͵�����
		bool haveValue;//���ڱ��item�Ƿ��Ѿ����������� 
	public:
		Store();
		T &getElem();//��ȡ���ݺ���
		void putElem(const T &x);//�������ݺ��� 
}; 
//������������ʵ��
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
		exit(1);//������ȫ�˳� 
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
	//dδ��ʼ����������ֹ 
}
