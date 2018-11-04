#include <iostream>
#include <string>
#include <stack>
#include <queue> 
#include <ctime>
using namespace std;
/*
优先级队列也像栈和队列一样支持元素的压入和弹出，但元素弹出的顺序与元素的大小有关，每次弹出的总是容器中最“大”的一个元素。

template <class T, class Sequence = vector<T> > class priority_queue;
优先级队列的基础容器必须是支持随机访问的顺序容器。

支持栈和队列的size、empty、push、pop几个成员函数，用法与栈和队列相同。
优先级队列并不支持比较操作。
与栈类似，优先级队列提供一个top函数，可以获得下一个即将被弹出元素（即最“大”的元素）的引用。
*/
const int SPLIT_TIME_MIN = 500;//细胞分裂的最短时间
const int SPLIT_TIME_MAX = 2000;//细胞分裂的最长时间
class Cell; 
priority_queue<Cell> cellQueue;
class Cell//细胞类 
{
	private:
		static int count;//细胞总数 
		int id;//细胞编号 
		int time;//细胞分裂时间
	public:
		Cell()
		{
			
		}
	    Cell(int birth) : id(count++) //birth为细胞诞生时间
		{ 
	        time = birth + (rand() % (SPLIT_TIME_MAX - SPLIT_TIME_MIN))+ SPLIT_TIME_MIN;//初始化，确定细胞分裂时间
	    }
	    int getId() const 
		{ 
			return id; 
		}        //得到细胞编号
	    int getSplitTime() const 
		{ 
			return time; 
		}   //得到细胞分裂时间
	    bool operator < (const Cell& s) const      //定义“<”
	    { 
			return time > s.time; 
		}
	    void split() const
		{  //细胞分裂
	        Cell child1(time), child2(time);    //建立两个子细胞
	        cout << time << "s: Cell #" << id << " splits to #"
	        << child1.getId() << " and #" << child2.getId() << endl;
	        cellQueue.push(child1); //将第一个子细胞压入优先级队列
	        cellQueue.push(child2); //将第二个子细胞压入优先级队列
	    }
};
int Cell::count = 0; 
int main()
{
	srand(static_cast<unsigned>(time(0)));
	int t;//模拟时间长度
	cout << "Simulateion time:";
	cin >> t; 
	cellQueue.push(Cell(0));//降低一个细胞压入优先级队列
	while(cellQueue.top().getSplitTime() <= t)
	{
		cellQueue.top().split();//模拟下一个细胞的分裂
		cellQueue.pop();//将刚刚分裂的细胞弹出 
	} 
}
