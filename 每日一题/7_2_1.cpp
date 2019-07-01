#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        vector<int> steps(number + 1, 0);
        steps[0] = 1;
        for(int i = 1; i < steps.size(); i++)
        {
            steps[i] = 0;
            for(int j = i - 1; j >= 0; j--)
            {
                steps[i] += steps[j];
            }
        }
        return steps[number];
    }
};
int main()
{

}