#pragma once

#include <iostream>
using std::cout;
using std::endl;
class Date
{
public:
  //得到某年某月中最大天数
  inline int GetMonthMaxDay(int month, int year) const//不改变对象因此改为常成员函数
  {
    //定义一年中每个月最大的天数数组
    int array[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
      return 29;
    }
    return array[month];
  }
  //构造函数
  Date(){}
  //构造函数重载
  Date(int year, int month, int day)
  {
    if(year > 1900 && month > 0 && month < 13 && day > 0 && day < GetMonthMaxDay(month, year))
    {
      _year = year;
      _month = month;
      _day = day;
    }
    else
    {
      //不合法情况
      cout << "wrong input" << endl;
    }
  }
  //析构函数
  ~Date(){}
  void Print() const
  {
    cout << _year << "-" << _month << "-" << _day << endl;
  }
  //+=运算符重载无需构造新的对象
  //由于对象不会销毁为了效率考虑我们可以返回以用
  Date& operator+=(int num);
  //调用，申请新的对象
  Date operator+(int num) const;
  //-=运算符重载无需构造新的对象
  //由于对象不会销毁为了效率考虑我们可以返回以用
  Date& operator-=(int num);
  Date operator-(int num) const;
  //前置++
  Date& operator++();
  //后置++
  Date operator++(int);
  //前置--
  Date& operator--();
  //后置--
  Date operator--(int);
  //比较相关:只用实现> = 剩下都可以调用实现
  bool operator>(const Date& date) const;
  bool operator==(const Date& date) const;
  bool operator>=(const Date& date) const;
  bool operator<(const Date& date) const;
  bool operator<=(const Date& date) const;
  bool operator!=(const Date& date) const;
  //计算两个日期间相差多少天
  int operator-(const Date& date) const;
private:
  int _year;//年
  int _month;//月
  int _day;//日
};
