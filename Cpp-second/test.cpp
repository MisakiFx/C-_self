#include <iostream>
#include <string>
#include <string.h>
#include <windows.h>
#include <vector>
//char *G2U(const char* gb2312)
//{
//    int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
//    wchar_t *wstr = new wchar_t[len + 1];
//    memset(wstr, 0, len + 1);
//    MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
//    len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
//    char *str = new char[len + 1];
//    memset(str, 0, len + 1);
//    WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
//    if (wstr)
//        delete[] wstr;
//    return str;
//}

//int main()
//{
//    std::string souce = "这是GB2312";
//    char* str = G2U(souce.c_str());
//    std::cout << str << std::endl;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int main()
//{
//    int N = 0, V = 0;
//    while(std::cin >> N >> V)
//    {
//        std::vector<int> V(N, 0), W(N, 0);
//        for(int i = 0; i < N; i++)
//        {
//            std::cin >> V[i] >> W[i];
//        }
//        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(V + 1, 0));
//        for(int i = 1; i <= N; i++)
//        {
//            for(int j = 1; j <= V; j++)
//            {
//                if(j > W[i])
//                {
//                    dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
//                }
//                else 
//                {
//                    dp[i][j] = dp[i - 1][j];
//                }
//            }
//        }
//        std::cout << dp[N][V] << std::endl;
//    }
//}
#include <iostream>

#include <iostream>
using namespace std;
class A
{
public:
};
//使用虚拟继承使B继承于A
class B: virtual public A
{
public:
};
//使用虚拟继承使C继承于A
class C: virtual public A
{
public:
    char _c = 'C';
};
//D继承于B,C
class D: public B, public C
{
public:
    char _d = 'D';
};
int main()
{
    std::cout << sizeof(B) << std::endl;
}