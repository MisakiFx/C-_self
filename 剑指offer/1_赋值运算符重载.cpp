#include <iostream>
#include <string.h>
using namespace std;
class CMyString
{
public:
    //构造函数
    CMyString(const char *pData)
        : m_pData(nullptr)
    {
        m_pData = new char[strlen(pData) + 1];
        strcpy(m_pData, pData);
    }
    //拷贝构造
    CMyString(const CMyString &myString)
    {
        if (myString.m_pData == nullptr)
        {
            m_pData == nullptr;
            return;
        }
        m_pData = new char[strlen(myString.m_pData) + 1];
        strcpy(m_pData, myString.m_pData);
    }
    //赋值运算符重载(普通版本)
    //CMyString& operator=(const CMyString& myString)
    //{
    //    //防止是同一个对象
    //    if(this == &myString)
    //    {
    //        return *this;
    //    }
    //    //释放原有资源
    //    delete[] m_pData;
    //    m_pData = nullptr;
    //    //申请新空间完成数据拷贝
    //    //这里申请失败可能会导致m_pData为nullptr抛异常，使原先对象失效,考虑异常安全，
    //    //因此我们要先申请成功后在释放原有空间
    //    m_pData = new char[strlen(myString.m_pData) + 1];
    //    strcpy(m_pData, myString.m_pData);
    //    return *this;
    //}
    ///进阶版赋值运算符重载，解决了异常安全问题
    CMyString &operator=(const CMyString &myString)
    {
        //防止是同一个对象
        if (this != &myString)
        {
            //调用拷贝构造构建临时对象，如果这一步失败，不会影响原有对象
            CMyString temp(myString);
            std::swap(m_pData, temp.m_pData);
            //临时对象会在生命周期结束后自动释放资源，带走原先应该释放的数据
        }
        return *this;
    }
    ~CMyString()
    {
        if (m_pData != nullptr)
        {
            delete[] m_pData;
        }
    }
    char *m_pData;
};
int main()
{
    CMyString myString("123");
    std::cout << myString.m_pData << std::endl;
    CMyString myString2(myString);
    std::cout << myString2.m_pData << std::endl;
    CMyString myString3("456");
    std::cout << myString3.m_pData << std::endl;
    myString3 = myString2;
    std::cout << myString3.m_pData << std::endl;
}