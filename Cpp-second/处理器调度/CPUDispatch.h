#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <Windows.h>
//PCB描述类
struct PCBStruct
{
	PCBStruct(const std::string& name, int runTime, int pri)
		:_name(name)
		,_next(nullptr)
		,_runTime(runTime)
		,_pri(pri)
		,_status('R')
	{}
	//属性
	std::string _name;			//姓名
	PCBStruct* _next;			//下一个PCB
	int _runTime;				//要求运行时间
	int _pri;					//优先数
	char _status;				//状态
};

//调度实现类
class Dispatch
{
public:
	//构造，随机加入count个PCB到队列中
	Dispatch(int count = 5);

	//打印所有进程及其信息
	void Print();
	
	//开始运行
	void Run();
private:
	PCBStruct* _PCBQueue;
	int _count;
};

Dispatch::Dispatch(int count)
	:_PCBQueue(nullptr)
	,_count(count)
{
	srand(time(nullptr));
	for (int i = 0; i < count; i++)
	{
		std::stringstream ss;
		ss << "P" << i + 1;
		PCBStruct* newPCB = new PCBStruct(ss.str(), rand() % 10 + 1, rand() % 10 + 1 );
		
		//找到合适的位置插入，这里的算法思想为插入排序
		PCBStruct* head = _PCBQueue;
		PCBStruct* prev = nullptr;
		while (head)
		{
			if (head->_pri <= newPCB->_pri)
			{
				newPCB->_next = head;
				if (prev == nullptr)
				{
					_PCBQueue = newPCB;
				}
				else
				{
					prev->_next = newPCB;
				}
				break;
			}
			prev = head;
			head = head->_next;
		}
		if (head == nullptr)
		{
			if (prev == nullptr)
			{
				_PCBQueue = newPCB;
			}
			else
			{
				prev->_next = newPCB;
			}
			newPCB->_next = nullptr;
		}
	}
}

void Dispatch::Print()
{
	PCBStruct* head = _PCBQueue;
	std::cout << "PCBQueue message:" << std::endl;
	while (head)
	{
		std::cout << "PCB name:" << head->_name << std::endl;
		std::cout << "PCB next:";
		if (head->_next == nullptr)
		{
			std::cout << "0" << std::endl;
		}
		else
		{
			std::cout << head->_next->_name << std::endl;
		}
		std::cout << "PCB run time:" << head->_runTime << std::endl;
		std::cout << "PCB pri:" << head->_pri << std::endl;
		std::cout << "PCB status:" << head->_status << std::endl;
		std::cout << std::endl;
		head = head->_next;
	}
}

void Dispatch::Run()
{
	int i = 1;
	while (_count > 0)
	{
		std::cout << "the " << i << " dispatch:" << std::endl;
		std::cout << "last count:" << _count << std::endl;
		if (_PCBQueue != nullptr)
		{
			//将第一个进程暂时弹出队列
			PCBStruct* cur = _PCBQueue;
			_PCBQueue = cur->_next;
			_count--;

			//执行第一个进程
			std::cout << "runing PCB message:" << std::endl;
			std::cout << "PCB name:" << cur->_name << std::endl;
			std::cout << "PCB next:";
			if (cur->_next == nullptr)
			{
				std::cout << "0" << std::endl;
			}
			else
			{
				std::cout << cur->_next->_name << std::endl;
			}
			std::cout << "PCB run time:" << cur->_runTime << std::endl;
			std::cout << "PCB pri:" << cur->_pri << std::endl;
			std::cout << "PCB status:" << cur->_status << std::endl;
			std::cout << std::endl;
			cur->_pri--;
			cur->_runTime--;

			//运行时间不为0，继续加入调度队列
			if (cur->_runTime > 0)
			{
				PCBStruct* head = _PCBQueue;
				PCBStruct* prev = nullptr;
				while (head)
				{
					if (head->_pri <= cur->_pri)
					{
						cur->_next = head;
						if (prev == nullptr)
						{
							_PCBQueue = cur;
						}
						else
						{
							prev->_next = cur;
						}
						break;
					}
					prev = head;
					head = head->_next;
				}
				if (head == nullptr)
				{
					if (prev == nullptr)
					{
						_PCBQueue = cur;
					}
					else
					{
						prev->_next = cur;
					}
					cur->_next = nullptr;
				}
				_count++;
			}
		}
		Print();
		i++;
		system("pause");
	}
}