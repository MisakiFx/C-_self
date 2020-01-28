#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    //求全排列
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str == "")
        {
            return res;
        }
        set<string> resSet;
        PermutationCore(str, 0, resSet);
        for(auto r : resSet)
        {
            res.push_back(r);
        }
        return res;
    }
    void PermutationCore(string& str, int index, set<string>& resSet)
    {
        if(index == str.size())
        {
            resSet.insert(str);
            return;
        }
        for(int i = index; i < str.size(); i++)
        {
            swap(str[i], str[index]);
            
            PermutationCore(str, index + 1, resSet);
            
            swap(str[i], str[index]);
        }
    }
    //求全组合
    vector<string> Combination(string str)
    {
        vector<string> res;
        if(str == "")
        {
            return res;
        }
        string resString;
        for(int i = 1; i <= str.size(); i++)
        {
            CombinationCore(str, 0, i, resString, res);
        }
        return res;
    }
    void CombinationCore(string str, int index, int num, string& resString, vector<string>& res)
    {
        if(num <= 0)
        {
            res.push_back(resString);
            return;
        }
        if(num > str.size() - index)
        {
            return;
        }
        resString.push_back(str[index]);
        CombinationCore(str, index + 1, num - 1, resString, res);
        resString.pop_back();
        CombinationCore(str, index + 1, num, resString, res);
    }
};

int main()
{
    Solution sol;
    vector<string> res = sol.Combination("abcd");
    for(auto s : res)
    {
        cout << s << endl;
    }
}