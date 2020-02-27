#include <iostream>
#include <deque>
#include <assert.h>

template <class T>
class Queue
{
public:
    Queue()
        :_curIndex(0)
    {}
    const T& GetMax()
    {
        assert(!_maxQue.empty());
        return _maxQue.front()._data;
    }
    void Push_Back(const T& data)
    {
        while(!_maxQue.empty() && data >= _maxQue.back()._data)
        {
            _maxQue.pop_back();
        }
        IndexQue tempIndex(data, _curIndex);
        _maxQue.push_back(tempIndex);
        _queue.push_back(tempIndex);
        _curIndex++;
    }
    void Pop_Front()
    {
        assert(!_queue.empty() && !_maxQue.empty());
        if(_queue.front()._index == _maxQue.front()._index)
        {
            _maxQue.pop_front();
        }
        _queue.pop_front();
    }
private:
    struct IndexQue
    {
        IndexQue(const T& data, int index)
            :_data(data)
            ,_index(index)
        {}
        T _data;
        int _index;
    };
    std::deque<IndexQue> _queue;
    std::deque<IndexQue> _maxQue;
    unsigned int _curIndex;
};
int main()
{
    Queue<int> que;
    que.Push_Back(6);
    que.Push_Back(4);
    que.Push_Back(3);
    que.Push_Back(6);
    que.Pop_Front();
    std::cout << que.GetMax() << std::endl;
}

