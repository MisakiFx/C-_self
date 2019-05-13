#include "Date.h"

Date& Date::operator+=(int num)
{
  _day += num;
  while(_day > GetMonthMaxDay(_month, _year))
  {
    _day -= GetMonthMaxDay(_month, _year);
    _month += 1;
    if(_month == 13)
    {
      _year += 1;
      _month -= 12;
    }
  }
  return *this;
}
Date& Date::operator-=(int num)
{
  _day -= num;
  while(_day < 1)
  {
    _day += GetMonthMaxDay(_month, _year);
    _month -= 1;
    if(_month == 0)
    {
      _year--;
      _month += 12;
    }
  }
  return *this;
}
Date Date::operator+(int num) const
{
  Date date(*this);//复制构造
  date+=(num);
  return date;
}
Date Date::operator-(int num) const
{
  Date date(*this);//复制构造
  date-=(num);
  return date;
}
Date& Date::operator++()
{
  *this += 1;
  return *this;
}
Date& Date::operator--()
{
  *this -= 1;
  return *this;
}
Date Date::operator++(int)
{
  Date date(*this);
  *this += 1;
  return date;
}
Date Date::operator--(int)
{
  Date date(*this);
  *this -= 1;
  return date;
}
bool Date::operator>(const Date& date) const
{
  if(_year > date._year)
  {
    return true;
  }
  else if(_year == date._year && _month > date._month)
  {
    return true;
  }
  else if(_year == date._year && _month == date._month && _day > date._day)
  {
    return true;
  }
  return false;
}
bool Date::operator==(const Date& date) const
{
  if(_year == date._year && _month == date._month && _day == date._day)
  {
    return true;
  }
  return false;
}
bool Date::operator>=(const Date& date) const
{
  if(*this > date || *this == date)
  {
    return true;
  }
  return false;
}
bool Date::operator<(const Date& date) const
{
  return !(*this >= date);
}
bool Date::operator<=(const Date& date) const
{
  if(*this < date || *this == date)
  {
    return true;
  }
  return false;
}
bool Date::operator!=(const Date& date) const
{
  return !(*this == date);
}
int Date::operator-(const Date& date) const
{
  int count = 0;
  Date dateTemp(*this);
  if(dateTemp == date)
  {
    return 0;
  }
  if(dateTemp < date)
  {
    while(dateTemp < date)
    {
      dateTemp++;
      count++;
    }
    return -count;
  }
  if(dateTemp > date)
  {
    while(dateTemp > date)
    {
      dateTemp--;
      count++;
    }
    return count;
  }
  
}