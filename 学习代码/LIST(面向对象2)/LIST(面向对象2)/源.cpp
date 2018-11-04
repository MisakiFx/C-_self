#include "Clist.h"
int main()
{
	Clist list1, list2;
	int choice1;
	do
	{
		cout << "请输入要操作的链表:";
		cin >> choice1;
		switch (choice1)
		{
		case 1:
			while (list1.Menu())
			{

			}
			break;
		case 2:
			while (list2.Menu())
			{

			}
			break;
		default:
			return 0;
			break;
		}
	} while (choice1 != 0);
}