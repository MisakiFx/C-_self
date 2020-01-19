#include <iostream>
#include <stack>

class Solution 
{
public:
    void push(int value) 
    {
        _s.push(value);
        if(!_fs.empty() && _fs.top() < value)
        {
            _fs.push(_fs.top());
        }
        else 
        {
            _fs.push(value);
        }
    }
    void pop() 
    {
        if(!_s.empty() && !_fs.empty())
        {
            _fs.pop();
            _s.pop();
        }
    }
    int top() {
        return _s.top();
    }
    int min() {
        return _fs.top();
    }
private:
    std::stack<int> _s;        //数据栈
    std::stack<int> _fs;       //辅助栈
};