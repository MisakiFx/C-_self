// write your code here cpp
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
    int num = 0;
    while(cin >> num)
    {
        set<string> res;
        for(int i = 0; i < num; i++)
        {
            string dir;
            cin >> dir;
            res.insert(dir);
        }
        set<string>::iterator it = res.begin();
        set<string>::iterator it2 = res.end();
        it2--;
        while(it != it2)
        {
            string pre = *it;
            set<string>:: iterator it3 = it;
            it3++;
            string suf = *it3;
            size_t pos = suf.rfind("/");
            string tempPre = suf.substr(0, pos);
            if(tempPre == pre)
            {
                it = res.erase(it);
                continue;
            }
            ++it;
        }
        it = res.begin();
        while(it != res.end())
        {
            cout << "mkdir -p " << *it << endl;
            it++;
        }
        cout << endl;
    }
}