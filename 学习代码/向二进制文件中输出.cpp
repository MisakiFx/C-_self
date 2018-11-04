#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
struct Date
{
	int mon, day, year;
};
int main()
{
	Date dt = {6, 10, 92};
	ofstream file("date.dat", ios_base::binary);
	file.write(reinterpret_cast<char*>(&dt),sizeof(dt));//临时类型转换，将dt的起始地址转换为char类型的指针 
	file.close();	
}
