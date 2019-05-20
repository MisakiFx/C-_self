#include <iostream>
#include <vector>
using namespace std;
//不会
//find the number of son array 
int main()
{
    int num = 0;
    cin >> num;
    vector<int> arr;
    arr.resize(num);
    for(int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    if(num <= 2)
    {
        cout << 1 << endl;
        return 0;
    }
    int count = 0;
    int flag = -1;//0 : < / 1 : > / 2 : =
    for(int i = 0; i < num - 1; i++)
    {
        int j = i + 1;
        int flagTemp = flag;
        if(arr[i] < arr[j])
        {
            flag = 0; 
        }
        else if(arr[i] > arr[j])
        {
            flag = 1;
        }
        else
        {
            flag = 2;
        }
        if(flag != flagTemp && flagTemp != 2 && flag != 2)
        {
            count++;
            cout << i << "\t" << count << endl;
        }
    }
    if(count == 0)
    {
        count += 1;
    }
    cout << count << endl;
}