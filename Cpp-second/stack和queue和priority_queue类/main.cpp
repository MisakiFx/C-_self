#include <iostream>     // std::cout
#include <queue>
#include <deque>
#include <functional>
using namespace std;
int main () 
{
    priority_queue<int, vector<int>, less<int>> que(less<int>(), vector<int>(3, 0));
}