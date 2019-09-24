#include <iostream>
#include <string>
using namespace std;
double Div(double num1, double num2)
{
    if (num2 == 0)
    {
        throw string("Division by zero condition");
        //cout << "Here" << endl;//不会执行了
    }
    //这里无法处理异常前往上层
    return num1 / num2;
}
void Func()
{
    int* arr = new int[10];
    try
    {
        Div(1, 0);
    }//跳到这里处理异常
    catch(const string errmsg)
    {
        //为了内存不泄露在这里先释放内存
        cout << "delete[]" << endl;
        delete[] arr;
        //抛给上层处理
        throw;
    }
    cout << "delete[]" << endl;
    delete[] arr;
}
int main()
{
    try
    {
        Func();
    }
    catch(const string errmsg)
    {
        cout << errmsg << endl;
    }
}