#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int>> array) 
    {
        int row = array.size();//行
        int col = array[0].size();//列
        for(int i = row - 1, j = 0; i >= 0 && j< col; )
        {
            if(target < array[i][j])
            {
                i--;
            }
            else if(target > array[i][j])
            {
                j++;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> array = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << sol.Find(0, array) << endl;
}