#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //这是从左下开始的找法，我们也可也从右上找
    bool Find1(int target, vector<vector<int>> array) 
    {
        int row = array.size();//行
        int col = array[0].size();//列
        for(int i = row - 1, j = 0; i >= 0 && j < col; )
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
    //从右上找
    bool Find2(int target, vector<vector<int>> arr)
    {
        int row = arr.size();
        int col = arr[0].size();
        for(int i = 0, j = col - 1; i < row && j >= 0; )
        {
            if(arr[i][j] > target)
            {
                j--;
            }
            else if(arr[i][j] < target)
            {
                i++;
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
    cout << sol.Find2(5, array) << endl;
}