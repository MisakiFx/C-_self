#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool isBro(string str1, string str2)
{
    if(str1 == str2)
    {
        return false;
    }
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    if(str1 == str2)
    {
        return true;
    }
    return false;
}
int main()
{
    int num;
    while(cin >> num)
    {
        vector<string> strs, bros;
        for(int i = 0; i < num; i++)
        {
            string temp;
            cin >> temp;
            strs.push_back(temp);
        }
        sort(strs.begin(), strs.end());
        string obj;
        int index;
        cin >> obj >> index;
        for(int i = 0; i < strs.size(); i++)
        {
            if(isBro(obj, strs[i]))
            {
                bros.push_back(strs[i]);
            }
        }
        cout << bros.size() << endl;
        if((index - 1) < bros.size())
        {
            cout << bros[index - 1] << endl;
        }
    }
}