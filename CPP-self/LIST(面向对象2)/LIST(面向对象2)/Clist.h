#pragma once
#include <iostream>
#include <cstring>
using namespace std;
typedef int DATA;
struct SNode
{
	DATA data;
	SNode* pNext;
};
class Clist
{
	void Print();
	void SetName(char* name);
	void AddHead(DATA data);
	SNode* m_pHead;
	char m_name[20];
	void Sort();
	void AddTail(DATA data);
public:
	Clist();
	~Clist();
	int Menu();
};

