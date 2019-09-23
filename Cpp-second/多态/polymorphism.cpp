#include <iostream>
using namespace std;
class Base1
{
public:
    virtual void func1()
    {
        cout << "Base1::func1()" << endl;
    }
    virtual void func2()
    {
        cout << "Base1::func2()" << endl;
    }
private:
    int _b1;
};
class Base2
{
public:
    virtual void func1()
    {
        cout << "Base2::func1()" << endl;
    }
    virtual void func2()
    {
        cout << "Base2::func2()" << endl;
    }
private:
    int _b2;
};
class Derive : public Base1, public Base2
{
    //发生重写/覆盖
public:
    virtual void func1()
    {
        cout << "Derive::func1()" << endl;
    }
    virtual void func3()
    {
        cout << "Derive::func3()" << endl;
    }
private:
    int _d;
};
typedef void (*VFPtr)();//虚函数指针
//打印虚函数表内容
void PrintVTable(VFPtr vTable[])//虚表本质上是一个虚函数指针数据
{
    cout << "vTable address:" << vTable << endl;
    for(int i = 0; vTable[i] != nullptr; i++)
    {
        printf("%dst vfptr of the vTable:0X%x -> ", i, vTable[i]);
        VFPtr func = vTable[i];
        func();
    }
}
int main()
{
    //取出虚函数表指针
    //对于单继承虚函数表指针就是对象的前4个字节，取出前四个字节再强转为VFPtr*类型即可
    Base1 b1;
    Base2 b2;
    Derive d;
    VFPtr* vTable1 = (VFPtr*)(*(int*)&b1);
    PrintVTable(vTable1);
    VFPtr* vTable2 = (VFPtr*)(*(int*)&b2);
    PrintVTable(vTable2);
    VFPtr* vTable3 = (VFPtr*)(*(int*)&d);
    PrintVTable(vTable3);
    //这里的多继承的派生类中的第二个虚表指针紧跟在第一个派生类成员之后
    VFPtr* vTable4 = (VFPtr*)(*(int*)((char*)&d + sizeof(Base1)));
    PrintVTable(vTable4);
}