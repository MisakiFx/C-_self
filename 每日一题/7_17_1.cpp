// write your code here cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    string A, B;
    while(cin >> A >> B)
    {
        map<char, int> ACount, BCount;
        for(int i = 0; i < A.size(); i++)
        {
            ACount[A[i]]++;
        }
        for(int i = 0; i < B.size(); i++)
        {
            BCount[B[i]]++;
        }
        map<char, int>::iterator it = BCount.begin();
        while(it != BCount.end())
        {
            if(ACount[it->first] < it->second)
            {
                break;
            }
            it++;
        }
        if(it == BCount.end())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}