#include "Banker.h"


int main()
{
	Banker* banker = Input();
	banker->Print();
	int processIndex = 0;
	std::vector<int> request(banker->ResouceNum());
	std::cout << "please input the process index:";
	std::cin >> processIndex;
	std::cout << "please input the process request resouce:" << std::endl;
	for (int i = 0; i < banker->ResouceNum(); i++)
	{
		std::cout << "process[" << processIndex << "] request resouce[" << i + 1 << "]:";
		std::cin >> request[i];
	}
	banker->IsAccept(processIndex, request);
	delete banker;
}