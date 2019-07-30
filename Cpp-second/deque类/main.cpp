#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> deq;
    deq.push_front(1);
    deq.push_back(2);
    deque<int>::iterator it = deq.begin();
    it = deq.insert(it, 0);
    while(it != deq.end())
    {
        cout << *it << endl;
        it++;
    }
    it = deq.erase(--it);
    it = deq.begin();
    while(it != deq.end())
    {
        cout << *it << endl;
        it++;
    }
}