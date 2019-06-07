#include <iostream>
#include <vector>
using namespace std;
bool isPerfect(int num)
{
    vector<int> primes;
    for(int i = 1; i < num; i++)
    {
        if(num % i == 0)
        {
            primes.push_back(i);
        }
    }
    int sum = 0;
    for(int i = 0; i < primes.size(); i++)
    {
        sum += primes[i];
    }
    if(sum == num)
    {
        return true;
    }
    return false;
}
int main()
{
    int num = 0;
    while(cin >> num)
    {
        int count = 0;
        for(int i = 1; i <= num; i++)
        {
            if(isPerfect(i))
            {
                count++;
            }
        }
        cout << count << endl;
    }
}