#include <iostream>
using namespace std;
template <class T>
class Node
{
	private:
		Node<T>* next;//地址区
	public:
		T data;
		Node(const T& item, Node<T>* next = 0);
		void insertAfter(Node<T>* p);//插入下一个结点的函数 
		Node<T>* deleteAfter();//删除当前结点下一个节点的函数 
		Node<T>* nextNode(); //返回下一个结点的指针 
		const Node<T>* nextNode() const;
};
template <class T>
Node<T>::Node(const T& data, Node<T>* next) : data(data), next(next)
{
	
}
template<class T>
Node<T>* Node<T>::nextNode()
{
	return next;	
}
template<class T>
const Node<T>* Node<T>::nextNode() const
{
	return next;	
}
template <class T>
void Node<T>::insertAfter(Node<T>* p)
{
	p->next = next;
	next = p;
}
template <class T>
Node<T>* Node<T>::deleteAfter()
{
	Node<T>* tempPtr = next;
	if(next == 0)
	{
		return 0;
	}
	next = tempPtr->next;
	return tempPtr;
}
int main()
{
	
}
