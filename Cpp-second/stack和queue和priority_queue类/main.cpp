#include <iostream>     // std::cout
#include <queue>
#include <vector>
#include "stack.h"
#include "queue.h"
#include "priority_queue.h"
using std::cout;
using std::endl;
//using namespace std;
int main () 
{
    //Stack<int> sta;
    //sta.Push(3);
    //sta.Push(4);
    //sta.Push(5);
    //while(!sta.Empty())
    //{
    //    std::cout << sta.Top() << " ";
    //    sta.Pop();
    //}
    //Queue<int> que;
    //que.Push(3);
    //que.Push(4);
    //que.Push(5);
    //while(!que.Empty())
    //{
    //    std::cout << que.Front() << " ";
    //    que.Pop();
    //}
    Priority_queue<int> que;
    que.Push(1);
    que.Push(5);
    que.Push(10);
    que.Push(4);
    que.Push(5);
    que.Push(100);
    while(!que.Empty())
    {
        std::cout << que.Top() << " ";
        que.Pop();
    }
}