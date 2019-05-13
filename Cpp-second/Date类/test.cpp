#include "Date.h"
int main()
{
  Date date(1999, 1, 20);
  Date date2(1999, 1, 20);
  cout << (date - date2) << endl;
}