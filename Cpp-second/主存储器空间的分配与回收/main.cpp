#include <iostream>
#include <vector>
#include <list>
struct Block
{
    Block(int startaddr, int length, std::string state = "未分配")
        :_startaddr(startaddr)
        ,_length(length)
        ,_state(state)
    {
    }
    int _startaddr;
    int _length;
    std::string _state;
};
class FirstFitBlock
{
public:
    //构造
    FirstFitBlock()
        :_memoryList()
    {
        _memoryList.push_back(Block(0, 200));
        _memoryList.push_back(Block(300, 500));
        _memoryList.push_back(Block(1000, 1000));
    }
    //分配作业空间
    void JoinDuty(std::string dutyName, int size)
    {
        std::list<Block>::iterator it = _memoryList.begin();
        while(it != _memoryList.end() && (it->_length < size || it->_state != "未分配"))
        {
            it++;
        }
        Block blockTemp(it->_startaddr, size, dutyName);
        it->_length -= size;
        it->_startaddr = it->_startaddr + size;
        it = _memoryList.insert(it, blockTemp);
    }
    //释放作业空间
    void FreeDuty(std::string dutyName)
    {
        std::list<Block>::iterator it = _memoryList.begin();
        while(it->_state != dutyName)
        {
            it++;
        }
        if(it == _memoryList.end())
        {
            std::cout << "error" << std::endl;
            return;
        }
        auto itTemp = ++it;
        it--;
        if(it->_startaddr + it->_length == itTemp->_startaddr && itTemp->_state == "未分配")
        {
            itTemp->_startaddr = it->_startaddr;
            itTemp->_length += it->_length;
            it = _memoryList.erase(it);
        }
        else 
        {
            it->_state = "未分配";
        }
    }
    //打印内存分区情况
    void PrintMemoryList()
    {
        std::cout << "主存分区情况：" << std::endl;
        std::cout << "起址" << "\t" << "长度" << "\t" << "状态" << std::endl;
        for(const auto& e : _memoryList)
        {
            std::cout << e._startaddr << "\t" << e._length << "\t" << e._state << std::endl;
        }
        std::cout << std::endl;
    }
    //打印空闲分区表
    void PrintFreeList()
    {
        std::cout << "空闲区说明表：" << std::endl;
        std::cout << "起址" << "\t" << "长度" << "\t" << "状态" << std::endl;
        for(const auto& e : _memoryList)
        {
            if(e._state == "未分配")
            {
                std::cout << e._startaddr << "\t" << e._length << "\t" << e._state << std::endl;
            }
        }
        std::cout << std::endl;
    }
private:
    std::list<Block> _memoryList;//分区表，包括未分配和已分配
};
int main()
{
    FirstFitBlock block;

    block.PrintFreeList();
    block.JoinDuty("作业1", 300);
    std::cout << "作业1申请300K" << std::endl << std::endl;;
    block.PrintMemoryList();

    block.PrintFreeList();
    block.JoinDuty("作业2", 100);
    std::cout << "作业2申请100K" << std::endl << std::endl;
    block.PrintMemoryList();

    block.PrintFreeList();
    block.FreeDuty("作业1");
    std::cout << "作业1释放300K" << std::endl << std::endl;;
    block.PrintMemoryList();

    block.PrintFreeList();
    block.JoinDuty("作业3", 150);
    std::cout << "作业3申请150K" << std::endl << std::endl;;
    block.PrintMemoryList();

    block.PrintFreeList();
    block.JoinDuty("作业4", 30);
    std::cout << "作业4申请30K" << std::endl << std::endl;;
    block.PrintMemoryList();
    
    block.PrintFreeList();
    block.JoinDuty("作业5", 40);
    std::cout << "作业5申请40K" << std::endl << std::endl;;
    block.PrintMemoryList();

    block.PrintFreeList();
    block.JoinDuty("作业6", 60);
    std::cout << "作业6申请60K" << std::endl << std::endl;;
    block.PrintMemoryList();

    block.PrintFreeList();
    block.FreeDuty("作业4");
    std::cout << "作业4释放30K" << std::endl << std::endl;;
    block.PrintMemoryList();
}