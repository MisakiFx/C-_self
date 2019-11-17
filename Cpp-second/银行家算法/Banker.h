#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
//����
class Banker;
//������ʼֵ����
Banker* Input();

class Banker
{
public:
	//����
	Banker(const std::vector<std::string>& resouceName, const std::vector<int>& avaliable, const std::vector<std::vector<int>>& max, const std::vector<std::vector<int>>& allocation);

	//��ӡ��Ϣ
	void Print();

	//�ж���Դ��ȡ�Ƿ��ȡ
	bool IsAccept(int processIndex, std::vector<int> request);

	//���ص�ǰ������
	int ProcessNum();

	//���ص�ǰ��Դ��
	int ResouceNum();
private:
	//�ж�ϵͳ��ȫ
	bool isSafe();

private:
	std::vector<std::string> _resouceName;			//��Դ����
	std::vector<int> _avaliable;					//�ɻ����Դ����
	std::vector<std::vector<int>> _max;				//���̻��ÿ����Դ�������
	std::vector<std::vector<int>> _allocation;		//�����ѻ��ÿ����Դ����
	std::vector<std::vector<int>> _need;			//���̻���Ҫ��Դ����
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
		//��һȦ��Ŀǰ���̻���û��ûִ�е�
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
		//���н��̶��Ѿ�ִ����ϣ�ϵͳ��ȫ
		if (i == finish.size())
		{
			return true;
		}
		for (i = 0; i < _need.size(); i++)
		{
			//���ҿ���ִ�еĽ���
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
					//ִ�к��ͷſռ䣬����ϵͳ������work��finish
					for (int j = 0; j < work.size(); j++)
					{
						work[j] += _allocation[i][j];
						finish[i] = true;
					}
					break;
				}
			}
		}
		//һȦ����û�п�ִ�еģ�ϵͳ����ȫ
		if (i == _need.size())
		{
			return false;
		}
	}
}

bool Banker::IsAccept(int processIndex, std::vector<int> request)
{
	//���벻��Ҫ��
	processIndex--;
	assert(processIndex >= 0 && processIndex < _processNum);
	if (request.size() != _avaliable.size())
	{
		std::cerr << "request input error" << std::endl;
		return false;
	}
	//ѭ���ж�ÿ����Դ�Ƿ񶼿��Ի��
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

	//�����Ȱ�������Դ���������
	for (int i = 0; i < request.size(); i++)
	{
		_avaliable[i] -= request[i];
		_allocation[processIndex][i] += request[i];
		_need[processIndex][i] -= request[i];
	}
	Print();
	//���а�ȫ��У��
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

//������ʼֵ����
Banker* Input()
{
	std::cout << "please input resouce num:";
	int resouceNum = 0;																			//��Դ����
	std::cin >> resouceNum;
	std::cout << "please input process num:";
	int processNum = 0;																			//��������
	std::cin >> processNum;

	std::vector<std::string> resouceName(resouceNum);											//��Դ����
	std::vector<int> resouce(resouceNum);														//��Դ����
	std::vector<std::vector<int>> max(processNum, std::vector<int>(resouceNum, 0));				//������Ҫ��Դ�������
	std::vector<std::vector<int>> allocation(processNum, std::vector<int>(resouceNum, 0));		//�����ѻ��ÿ����Դ����

	//��ʼ��������
	//������Դ���ƺ�����
	std::cout << "please input resouce name and num(name num):" << std::endl;
	for (int i = 0; i < resouceNum; i++)
	{
		std::cout << "resouce [" << i + 1 << "]:";
		std::cin >> resouceName[i];
		std::cin >> resouce[i];
	}
	//����ÿ��������Ҫ�������Դ����
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