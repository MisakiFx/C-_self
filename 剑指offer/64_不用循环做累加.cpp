/*
template<int n>
class Sol
{
    public:
    enum
    {
        N = Sol<n - 1>::N + n
    };
};
template<>
class Sol<1>
{
    enum
    {
          N = 1
    };
}; 
class Solution {
public:
    int Sum_Solution(int n) {
        return Sol<n>::N;
    }
};
*/
class Solution {
public:
    class Sol
    {
    public:
        Sol()
        {
            sum += num;
            num++;
        }
        static int sum;
        static int num;
    };
    int Sum_Solution(int n) {
        Sol* sol = new Sol[n];
        int temp = Sol::sum;
        Sol::sum = 0;
        Sol::num = 1;
        return temp;
    }
};
    int Solution::Sol::sum = 0;
    int Solution::Sol::num = 1;