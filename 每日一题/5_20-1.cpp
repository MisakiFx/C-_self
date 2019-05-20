//组队竞赛
//给出组队的数量和每个人数的能力值，队伍能力值为队伍中第二高的个人能力值
//要求输出最优方案下队伍能力的综合
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool MyFun(int x, int y)
{
  return x < y;
}
int main()
{
  int numOfCount = 0;
  cin >> numOfCount;
  vector<int> a_i;
  int temp = 0;
  for (int i = 0; i < 3 * numOfCount; i++) {
    cin >> temp;
    a_i.push_back(temp);
  }
  sort(a_i.begin(), a_i.end(), MyFun);
  int sum = 0;
  for(int i = 0, j = a_i.size(); i < numOfCount; i++)
  {
    j -= 2;
    sum += a_i[j];
  }
  cout << sum << endl;
}
