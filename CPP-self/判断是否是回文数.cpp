#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }
        long long rev = 0;
        int temp = x;
        while(temp)
        {
            int t = temp % 10;
            temp /= 10;
            rev =  rev * 10 + t;
        }
        if(rev == x)
        {
            return true;
        }
        return false;
    }
};
int main()
{

}