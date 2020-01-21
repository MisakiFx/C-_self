#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() <= 0)
        {
            return false;
        }
        int root = sequence[sequence.size() - 1];
        vector<int>::iterator i = sequence.begin();
        while(i < (--sequence.end()))
        {
            if(*i > root)
            {
                break;
            }
            i++;
        }
        vector<int>::iterator j = i;
        while(j < (--sequence.end()))
        {
            if(*j < root)
            {
                return false;
            }
            j++;
        }
        bool left = true;
        if(i > sequence.begin())
        {
            left = VerifySquenceOfBST(vector<int>(sequence.begin(), i));
        }
        bool right = true;
        if(i < (--sequence.end()))
        {
            right = VerifySquenceOfBST(vector<int>(i, (--sequence.end())));
        }
        return left && right;
    }
};
