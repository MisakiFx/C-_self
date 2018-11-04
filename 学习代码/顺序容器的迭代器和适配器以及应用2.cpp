#include <iostream>
#include <string>
#include <stack>
#include <queue> 
#include <ctime>
using namespace std;
/*
���ȼ�����Ҳ��ջ�Ͷ���һ��֧��Ԫ�ص�ѹ��͵�������Ԫ�ص�����˳����Ԫ�صĴ�С�йأ�ÿ�ε�����������������󡱵�һ��Ԫ�ء�

template <class T, class Sequence = vector<T> > class priority_queue;
���ȼ����еĻ�������������֧��������ʵ�˳��������

֧��ջ�Ͷ��е�size��empty��push��pop������Ա�������÷���ջ�Ͷ�����ͬ��
���ȼ����в���֧�ֱȽϲ�����
��ջ���ƣ����ȼ������ṩһ��top���������Ի����һ������������Ԫ�أ�����󡱵�Ԫ�أ������á�
*/
const int SPLIT_TIME_MIN = 500;//ϸ�����ѵ����ʱ��
const int SPLIT_TIME_MAX = 2000;//ϸ�����ѵ��ʱ��
class Cell; 
priority_queue<Cell> cellQueue;
class Cell//ϸ���� 
{
	private:
		static int count;//ϸ������ 
		int id;//ϸ����� 
		int time;//ϸ������ʱ��
	public:
		Cell()
		{
			
		}
	    Cell(int birth) : id(count++) //birthΪϸ������ʱ��
		{ 
	        time = birth + (rand() % (SPLIT_TIME_MAX - SPLIT_TIME_MIN))+ SPLIT_TIME_MIN;//��ʼ����ȷ��ϸ������ʱ��
	    }
	    int getId() const 
		{ 
			return id; 
		}        //�õ�ϸ�����
	    int getSplitTime() const 
		{ 
			return time; 
		}   //�õ�ϸ������ʱ��
	    bool operator < (const Cell& s) const      //���塰<��
	    { 
			return time > s.time; 
		}
	    void split() const
		{  //ϸ������
	        Cell child1(time), child2(time);    //����������ϸ��
	        cout << time << "s: Cell #" << id << " splits to #"
	        << child1.getId() << " and #" << child2.getId() << endl;
	        cellQueue.push(child1); //����һ����ϸ��ѹ�����ȼ�����
	        cellQueue.push(child2); //���ڶ�����ϸ��ѹ�����ȼ�����
	    }
};
int Cell::count = 0; 
int main()
{
	srand(static_cast<unsigned>(time(0)));
	int t;//ģ��ʱ�䳤��
	cout << "Simulateion time:";
	cin >> t; 
	cellQueue.push(Cell(0));//����һ��ϸ��ѹ�����ȼ�����
	while(cellQueue.top().getSplitTime() <= t)
	{
		cellQueue.top().split();//ģ����һ��ϸ���ķ���
		cellQueue.pop();//���ոշ��ѵ�ϸ������ 
	} 
}
