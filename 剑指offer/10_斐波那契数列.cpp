class Solution
{
public:
    int Fibonacci_digui(int n)
    {
        if (n < 2)
        {
            return n;
        }
        return Fibonacci_digui(n - 1) + Fibonacci_digui(n - 2);
    }
    //迭代解法
    int Fibonacci(int n)
    {
        if (n < 2)
        {
            int arr[2] = {0, 1};
            return arr[n];
        }
        long long fib1 = 0, fib2 = 1, fibn = 0;
        for (int i = 2; i <= n; i++)
        {
            fibn = fib1 + fib2;
            fib1 = fib2;
            fib2 = fibn;
        }
        return fibn;
    }
};