#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        std::vector<int> res(A.size(), 0);
        res[0] = 1;
        for(int i = 1; i < A.size(); i++)
        {
            res[i] = res[i - 1] * A[i - 1];
        }
        int temp = 1;
        for(int i = A.size() - 2; i >= 0; i--)
        {
            temp *= A[i + 1];
            res[i] *= temp;
        }
        return res;
    }
};