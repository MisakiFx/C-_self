#include <iostream>
#include <string>
#include <vector>
#include "Vector.h"
using namespace std;
int main()
{
    Vector<int> arr(4, 6);
    arr.Reserve(20);
    Vector<int> arr2;
    arr2 = arr;
    for(int i = 0; i < arr2.Size(); i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << arr2.Capacity() << " " << arr2.Size() << endl;
    //cout << arr.Capacity() << endl;
    //cout << arr.Size() << endl;
    //arr.Reserve(10);
    //cout << arr.Capacity() << endl;
    //arr.Resize(20);
    //cout << arr.Capacity() << endl;
    //cout << arr.Size() << endl;
}