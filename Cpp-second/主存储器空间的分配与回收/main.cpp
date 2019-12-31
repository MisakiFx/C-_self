#include <iostream>
#include <vector>
#include <list>
struct Block
{
    Block(int startaddr, int length, std::string state = "δ����")
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
    //����
    FirstFitBlock()
        :_memoryList()
    {
        _memoryList.push_back(Block(0, 200));
        _memoryList.push_back(Block(300, 500));
        _memoryList.push_back(Block(1000, 1000));
    }
    //������ҵ�ռ�
    void JoinDuty(std::string dutyName, int size)
    {
        std::list<Block>::iterator it = _memoryList.begin();
        while(it != _memoryList.end() && (it->_length < size || it->_state != "δ����"))
        {
            it++;
        }
        Block blockTemp(it->_startaddr, size, dutyName);
        it->_length -= size;
        it->_startaddr = it->_startaddr + size;
        it = _memoryList.insert(it, blockTemp);
    }
    //�ͷ���ҵ�ռ�
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
        if(it->_startaddr + it->_length == itTemp->_startaddr && itTemp->_state == "δ����")
        {
            itTemp->_startaddr = it->_startaddr;
            itTemp->_length += it->_length;
            it = _memoryList.erase(it);
        }
        else 
        {
            it->_state = "δ����";
        }
    }
    //��ӡ�ڴ�������
    void PrintMemoryList()
    {
        std::cout << "������������" << std::endl;
        std::cout << "��ַ" << "\t" << "����" << "\t" << "״̬" << std::endl;
        for(const auto& e : _memoryList)
        {
            std::cout << e._startaddr << "\t" << e._length << "\t" << e._state << std::endl;
        }
        std::cout << std::endl;
    }
    //��ӡ���з�����
    void PrintFreeList()
    {
        std::cout << "������˵����" << std::endl;
        std::cout << "��ַ" << "\t" << "����" << "\t" << "״̬" << std::endl;
        for(const auto& e : _memoryList)
        {
            if(e._state == "δ����")
            {
                std::cout << e._startaddr << "\t" << e._length << "\t" << e._state << std::endl;
            }
        }
        std::cout << std::endl;
    }
private:
    std::list<Block> _memoryList;//����������δ������ѷ���
};
int main()
{
    FirstFitBlock block;

    block.PrintFreeList();
    block.JoinDuty("��ҵ1", 300);
    std::cout << "��ҵ1����300K" << std::endl << std::endl;;
    block.PrintMemoryList();

    block.PrintFreeList();
    block.JoinDuty("��ҵ2", 100);
    std::cout << "��ҵ2����100K" << std::endl << std::endl;
    block.PrintMemoryList();

    block.PrintFreeList();
    block.FreeDuty("��ҵ1");
    std::cout << "��ҵ1�ͷ�300K" << std::endl << std::endl;;
    block.PrintMemoryList();

    block.PrintFreeList();
    block.JoinDuty("��ҵ3", 150);
    std::cout << "��ҵ3����150K" << std::endl << std::endl;;
    block.PrintMemoryList();

    block.PrintFreeList();
    block.JoinDuty("��ҵ4", 30);
    std::cout << "��ҵ4����30K" << std::endl << std::endl;;
    block.PrintMemoryList();
    
    block.PrintFreeList();
    block.JoinDuty("��ҵ5", 40);
    std::cout << "��ҵ5����40K" << std::endl << std::endl;;
    block.PrintMemoryList();

    block.PrintFreeList();
    block.JoinDuty("��ҵ6", 60);
    std::cout << "��ҵ6����60K" << std::endl << std::endl;;
    block.PrintMemoryList();

    block.PrintFreeList();
    block.FreeDuty("��ҵ4");
    std::cout << "��ҵ4�ͷ�30K" << std::endl << std::endl;;
    block.PrintMemoryList();
}