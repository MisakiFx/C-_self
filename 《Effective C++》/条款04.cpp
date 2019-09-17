//#include <iostream>
//using namespace std;
//class PhoneNumber
//{
//public:
//    PhoneNumber()
//    {
//        cout << "PhoneNumber()" << endl;
//    }
//    PhoneNumber(string theNumber)
//    {
//        cout << "PhoneNumber(string theNumber)" << endl;
//        string _theNumber;
//    }
//    PhoneNumber(const PhoneNumber& phoneNumber)
//    {
//        _theNumber = phoneNumber._theNumber;
//        cout << "PhoneNumber(const PhoneNumber& phoneNumber)" << endl;
//    }
//    PhoneNumber operator=(const PhoneNumber& phoneNumber)
//    {
//        _theNumber = phoneNumber._theNumber;
//        cout << "PhoneNumber operator=(const PhoneNumber& phoneNumber))" << endl;
//    }
//private:
//    string _theNumber;
//};
//class ABEntry
//{
//public:
//    //这样才能对成员进行初始化，从结果也可以看出这里少了一次无参的默认构造
//    ABEntry(const string& theName, const string& theAddress, const PhoneNumber& theNumber)
//        :_theName(theName)
//        ,_theAddress(theAddress)
//        ,_theNumber(theNumber)
//    {
//    }
//private:
//    string _theName;
//    string _theAddress;
//    PhoneNumber _theNumber;
//};
#include <iostream>
#include "FileSystem.h"
using namespace std;
class Directory
{
public:
    Directory()
    {
        _disks = tfs().numDisks();
    }
    size_t _disks;
};
int main()
{
    Directory dir;
    cout << dir._disks << endl;
}