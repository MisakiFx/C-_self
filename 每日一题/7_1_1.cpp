#include<iostream>
#include<string>
using namespace std;
 
int numberRoot(string num)
{
    int cur = num[num.size() - 1] - '0';
    while (num.size() > 1)
    {
        cur = 0;
        for (auto& c : num)
        {
            cur += c - '0';
        }
        num = to_string(cur);
    }
    return cur;
}
int main()
{
    string num;
    while (cin >> num)
    {
        cout << numberRoot(num) << endl;
    }
    return 0;
}