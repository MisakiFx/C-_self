//求最近父结点
#include <iostream>
using namespace std;
class LCA {
public:
    int getLCA(int a, int b) {
        if(a < b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        if((2 * a == b) || ((2 * a + 1) == b) || (a == b))
        {
            return a;
        }
        return getLCA(a / 2, b);
    }
};
int main()
{
    LCA l;
    cout << (l.getLCA(5, 4)) << endl;
}