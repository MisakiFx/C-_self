//#include <iostream>
//#include <string>
//using namespace std;
//void Change(string& str)
//{
//    for(int i = 0; i < str.size(); i++)
//    {
//        if(str[i] == ' ')
//        {
//            str.erase(i, 1);
//            str.insert(i, "%20");
//        }
//    }
//}
//int main()
//{
//    string str = "abc defgx yz";
//    Change(str);
//    cout << str << endl;
//}
//#include <iostream>
//using namespace std;
//long long Fib(int n)
//{
//    if(n <= 2)
//    {
//        return 1;
//    }
//    long long fib1 = 1, fib2 = 1;
//    for(int i = 3; i <= n; i++)
//    {
//        long long fib = fib1 + fib2;
//        fib1 = fib2;
//        fib2 = fib;
//    }
//    return fib2;
//}
//int main()
//{
//    cout << Fib(5) << endl;
//}
#include <stdio.h>
#define F(X, Y) ((X)+(Y))
int main()
{
    enum ENUM_A
    {
        X1,
        Y1,
        Z1 = 5,
        A1,
        B1
    };
    enum ENUM_A enumA = Y1;
    enum ENUM_A enumB = B1;
    printf("%d %d\n", enumA, enumB);
} 