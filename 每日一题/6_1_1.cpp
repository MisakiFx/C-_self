//位插入
#include <iostream>
using namespace std;
class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        m <<= j;
        cout << m << endl;
        n |= m;
        return n;
    }
};
int main()
{
    BinInsert bin;
    cout << bin.binInsert(1024, 19, 2, 6) << endl;
}