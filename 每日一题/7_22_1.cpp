#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int num = 0;
    while(cin >> num)
    {
        stack<char> cot;
        int maxSize = 0;
        for(int i = 0; i < num; i++)
        {
            char name;
            string operate;
            cin >> name >> operate;
            if(operate == "connect")
            {
                cot.push(name);
            }
            else
            {
                cot.pop();
            }
            if(cot.size() > maxSize)
            {
                maxSize = cot.size();
            }
        }
        cout << maxSize << endl;
    }
}