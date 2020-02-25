#include <iostream>
#include <string>
#include <stack>
using namespace std;


/*
class Solution {
public:
    string ReverseSentence(string str) {
        stack<string> arr;
        int i = 0;
        int res = 0;
        while((res = str.find(" ", i)) != string::npos)
        {
            string temp = str.substr(i, res - i);
            arr.push(temp);
            i = res + 1;
        }
        arr.push(str.substr(i));
        string realRes;
        while(!arr.empty())
        {
            realRes += arr.top();
            realRes += " ";
            arr.pop();
        }
        realRes.pop_back();
        return realRes;
    }
};
*/

class Solution {
public:
    //左闭右闭区间
    void Reverse(string& str, int start, int end)
    {
        if(str.size() <= 1)
        {
            return;
        }
        while(start < end)
        {
            swap(str[start], str[end]);
            start++;
            end--;
        }
    }
    string ReverseSentence(string str) {
        Reverse(str, 0, str.size() - 1);
        int start = 0, end = 0;
        while(start < str.size())
        {
            if(str[end] == ' ' || str[end] == '\0')
            {
                Reverse(str, start, end - 1);
                end++;
                start = end;
            }
            else 
            {
                end++;
            }
        }
        return str;
    }
};