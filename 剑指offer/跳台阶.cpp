#include <iostream>
class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 0)
        {
            return 0;
        }
        int arr[] = {1, 2};
        if(number <= 2)
        {
            return arr[number - 1];
        }
        for(int i = 3; i <= number; i++)
        {
            int sum = arr[0] + arr[1];
            arr[0] = arr[1];
            arr[1] = sum;
        }
        return arr[1];
    }
};