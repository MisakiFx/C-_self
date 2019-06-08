//兄弟你让我求斐波那契我能不会么，你让我求尼玛兔子啊！！！！
#include <iostream>
#include <vector>
using namespace std;
int getNumOfRebit(int month)
{
    if(month < 3)
    {
        return 1;
    }
    return getNumOfRebit(month - 1) + getNumOfRebit(month - 2);
}
int main()
{
    int month = 0;
    while(cin >> month)
    {
        cout << getNumOfRebit(month) << endl;
    }
}
