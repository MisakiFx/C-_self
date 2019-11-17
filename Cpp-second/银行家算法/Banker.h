#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
//声明
class Banker;
//用作初始值输入
Banker* Input();

class Banker
{
public:
	//构造
	Banker(const std::vector<std::string>& resouceName, const std::vector<int>& avaliable, const std::vector<std::vector<int>>& max, const std::vector<std::vector<int>>& allocation);

	//打印信息
	void Print();

	//判断资源获取是否可取
	bool IsAccept(int processIndex, std::vector<int> request);

	//返回当前进程数
	int ProcessNum();

	//返回当前资源数
	int ResouceNum();
private:
	//判断系统安全
	bool isSafe();

private:
	std::vector<std::string> _resouceName;			//资源名称
	std::vector<int> _avaliable;					//可获得资源数量
	std::vector<std::vector<int>> _max;				//进程获得每种资源最大数量
	std::vector<std::vector<int>> _allocation;		//进程已获得每种资源数量
	std::vector<std::vector<int>> _need;			//进程还需要资源数量
	int _processNum;
	int _resouceNum;
};

int Banker::ResouceNum()
{
	return _resouceNum;
}

int Banker::ProcessNum()
{
	return _processNum;
}

Banker::Banker(const std::vector<std::string>& resouceName, const std::vector<int>& avaliable, const std::vector<std::vector<int>>& max, const std::vector<std::vector<int>>& allocation)
	:_resouceName(resouceName)
	,_avaliable(avaliable)
	,_max(max)
	,_allocation(allocation)
	,_need(_max.size(), std::vector<int>(_max[0].size(), 0))
	,_processNum(_need.size())
	,_resouceNum(_need[0].size())
{
	for (int i = 0; i < _need.size(); i++)
	{
		for (int j = 0; j < _need[0].size(); j++)
		{
			_need[i][j] = _max[i][j] - _allocation[i][j];
			assert(_need[i][j] >= 0);
		}
	}
}

inline void Banker::Print()
{
	std::cout << "*********************************************" << std::endl;
	std::cout << "avaliable:" << std::endl;
	std::cout << "\t\t";
	for (auto e : _resouceName)
	{
		std::cout << e << "\t";
	}
	std::cout << std::endl;
	std::cout << "\t\t";
	for (auto e : _avaliable)
	{
		std::cout << e << "\t";
	}
	std::cout << std::endl;

	std::cout << "max:" << std::endl;
	std::cout << "\t\t";
	for (auto e : _resouceName)
	{
		std::cout << e << "\t";
	}
	std::cout << std::endl;
	for (int i = 0; i < _max.size(); i++)
	{
		std::cout << "prce[" << i + 1 << "]\t\t";
		for (int j = 0; j < _max[0].size(); j++)
		{
			std::cout << _max[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	std::cout << "allocation:" << std::endl;
	std::cout << "\t\t";
	for (auto e : _resouceName)
	{
		std::cout << e << "\t";
	}
	std::cout << std::endl;
	for (int i = 0; i < _allocation.size(); i++)
	{
		std::cout << "prce[" << i + 1 << "]\t\t";
		for (int j = 0; j < _allocation[0].size(); j++)
		{
			std::cout << _allocation[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	std::cout << "need:" << std::endl;
	std::cout << "\t\t";
	for (auto e : _resouceName)
	{
		std::cout << e << "\t";
	}
	std::cout << std::endl;
	for (int i = 0; i < _need.size(); i++)
	{
		std::cout << "prce[" << i + 1 << "]\t\t";
		for (int j = 0; j < _need[0].size(); j++)
		{
			std::cout << _need[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "**********************************************" << std::endl;
}

bool Banker::isSafe()
{
	std::vector<int> work = _avaliable;
	std::vector<bool> finish(_need.size(), false);
	while (1)
	{
		//找一圈看目前进程还有没有没执行的
		std::cout << "finish:" << std::endl;
		for (auto e : finish)
		{
			std::cout << e << "\t";
		}
		std::cout << std::endl;
		std::cout << "work:" << std::endl;
		for (auto e : _resouceName)
		{
			std::cout << e << "\t";
		}
		std::cout << std::endl;
		for (auto e : work)
		{
			std::cout << e << "\t";
		}
		std::cout << std::endl;
		int i = 0;
		for (i = 0; i < finish.size(); i++)
		{
			if (finish[i] == false)
			{
				break;
			}
		}
		//所有进程都已经执行完毕，系统安全
		if (i == finish.size())
		{
			return true;
		}
		for (i = 0; i < _need.size(); i++)
		{
			//查找可以执行的进程
			if (finish[i] == false)
			{
				bool canRun = true;
				for (int j = 0; j < _need[i].size(); j++)
				{
					if (_need[i][j] > work[j])
					{
						canRun = false;
						break;
					}
				}
				if (canRun == true)
				{
					std::cout << "running process:" << i + 1 << std::endl;;
					//执行后释放空间，还给系统，更新work和finish
					for (int j = 0; j < work.size(); j++)
					{
						work[j] += _allocation[i][j];
						finish[i] = true;
					}
					break;
				}
			}
		}
		//一圈找完没有可执行的，系统不安全
		if (i == _need.size())
		{
			return false;
		}
	}
}

bool Banker::IsAccept(int processIndex, std::vector<int> request)
{
	//输入不符要求
	processIndex--;
	assert(processIndex >= 0 && processIndex < _processNum);
	if (request.size() != _avaliable.size())
	{
		std::cerr << "request input error" << std::endl;
		return false;
	}
	//循环判断每个资源是否都可以获得
	for (int i = 0; i < request.size(); i++)
	{
		if (request[i] > _need[processIndex][i])
		{
			std::cerr << "request the resouce more than the max" << std::endl;
			return false;
		}
		if (request[i] > _avaliable[i])
		{
			std::cerr << "system can not offer the enough resouce, you must wait" << std::endl;
			return false;
		}
	}

	//假设先把所有资源分配给进程
	for (int i = 0; i < request.size(); i++)
	{
		_avaliable[i] -= request[i];
		_allocation[processIndex][i] += request[i];
		_need[processIndex][i] -= request[i];
	}
	Print();
	//进行安全性校验
	bool ret = isSafe();
	if (ret == true)
	{
		std::cout << "request accept" << std::endl;
		Print();
		return true;
	}
	for (int i = 0; i < request.size(); i++)
	{
		_avaliable[i] += request[i];
		_allocation[processIndex][i] -= request[i];
		_need[processIndex][i] += request[i];
	}
	std::cout << "request reject, wait" << std::endl;
	Print();
	return false;
}

//用作初始值输入
Banker* Input()
{
	std::cout << "please input resouce num:";
	int resouceNum = 0;																			//资源数量
	std::cin >> resouceNum;
	std::cout << "please input process num:";
	int processNum = 0;																			//进程数量
	std::cin >> processNum;

	std::vector<std::string> resouceName(resouceNum);											//资源名称
	std::vector<int> resouce(resouceNum);														//资源数量
	std::vector<std::vector<int>> max(processNum, std::vector<int>(resouceNum, 0));				//进程需要资源最大数量
	std::vector<std::vector<int>> allocation(processNum, std::vector<int>(resouceNum, 0));		//进程已获得每种资源数量

	//开始输入数据
	//输入资源名称和数量
	std::cout << "please input resouce name and num(name num):" << std::endl;
	for (int i = 0; i < resouceNum; i++)
	{
		std::cout << "resouce [" << i + 1 << "]:";
		std::cin >> resouceName[i];
		std::cin >> resouce[i];
	}
	//输入每个进程需要的最大资源数量
	std::cout << "please input process need the max resouce:" << std::endl;
	for (int i = 0; i < max.size(); i++)
	{
		for (int j = 0; j < max[0].size(); j++)
		{
			std::cout << "process [" << i + 1 << "] need the max resouce [" << resouceName[j] << "]:";
			std::cin >> max[i][j];
		}
	}
	std::cout << "please input process have allocated resouce:" << std::endl;
	for (int i = 0; i < allocation.size(); i++)
	{
		for (int j = 0; j < allocation[0].size(); j++)
		{
			std::cout << "process [" << i + 1 << "] have allocated resouce [" << resouceName[j] << "]:";
			std::cin >> allocation[i][j];
		}
	}
	Banker* banker = new Banker(resouceName, resouce, max, allocation);
	return banker;
}