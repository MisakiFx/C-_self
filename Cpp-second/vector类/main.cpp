#include <iostream>
#include <string>
#include <vector>
#include "Vector.h"
using namespace std;
int main()
{
    Vector<int> arr(4, 6);
    //Vector<int>::iterator it = arr.Insert(arr.begin(), 1);
    //Vector<int>::iterator it2 = arr.Erase(arr.begin());
    for(int i = 0; i < arr.Size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << arr.Capacity() << " " << arr.Size() << endl;
    //cout << *it2 << endl;
    //cout << arr.Capacity() << endl;
    //cout << arr.Size() << endl;
    //arr.Reserve(10);
    //cout << arr.Capacity() << endl;
    //arr.Resize(20);
    //cout << arr.Capacity() << endl;
    //cout << arr.Size() << endl;
}