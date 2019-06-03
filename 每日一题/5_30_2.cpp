//https://www.nowcoder.com/practice/52d382c2a7164767bca2064c1c9d5361?tpId=37&&tqId=21310&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
/**
 * 题目描述
密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。

       一、密码长度:

       5 分: 小于等于4 个字符

       10 分: 5 到7 字符

       25 分: 大于等于8 个字符

       二、字母:

       0 分: 没有字母

       10 分: 全都是小（大）写字母

       20 分: 大小写混合字母

       三、数字:

       0 分: 没有数字

       10 分: 1 个数字

       20 分: 大于1 个数字

       四、符号:

       0 分: 没有符号

       10 分: 1 个符号

       25 分: 大于1 个符号

       五、奖励:

       2 分: 字母和数字

       3 分: 字母、数字和符号

       5 分: 大小写字母、数字和符号

       最后的评分标准:

       >= 90: 非常安全

       >= 80: 安全（Secure）

       >= 70: 非常强

       >= 60: 强（Strong）

       >= 50: 一般（Average）

       >= 25: 弱（Weak）

       >= 0:  非常弱

 

对应输出为：

  VERY_WEAK,

   WEAK,    

   AVERAGE,    

   STRONG,     

   VERY_STRONG,

   SECURE,     

   VERY_SECURE 



       请根据输入的密码字符串，进行安全评定。

       注：

       字母：a-z, A-Z

       数字：-9

       符号包含如下： (ASCII码表可以在UltraEdit的菜单view->ASCII Table查看)

       !"#$%&'()*+,-./     (ASCII码：x21~0x2F)

       :;<=>?@             (ASCII<=><=><=><=><=>码：x3A~0x40)

       [\]^_`              (ASCII码：x5B~0x60)

  {|}~                (ASCII码：x7B~0x7E)

接口描述：

 

 Input Param 
      String pPasswordStr:    密码，以字符串方式存放。

 Return Value
   根据规则评定的安全等级。

 

 
 public static Safelevel GetPwdSecurityLevel(String pPasswordStr)
 {
    //在这里实现功能
  return null;
 }
 
输入描述:
输入一个string的密码

输出描述:
输出密码等级

示例1

输入
38$@NoNoNo

输出
VERY_SECURE
 */
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    while(cin >> str)
    {
        int grade = 0;
        int numOfBigAlpha = 0;
        int numOfSmallAlpha = 0;
        int numOfDigit = 0;
        int numOfOther = 0;
        if(str.size() <= 4)
        {
            grade += 5;
        }
        else if(str.size() >= 5 && str.size() <= 7)
        {
            grade += 10;
        }
        else if(str.size() >= 8)
        {
            grade += 25;
        }
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                numOfSmallAlpha++;
            }
            else if(str[i] >= 'A' && str[i] <= 'Z')
            {
                numOfBigAlpha++;
            }
            else if(str[i] >= '0' && str[i] <= '9')
            {
                numOfDigit++;
            }
            else
            {
                numOfOther++;
            }
        }
        if(numOfSmallAlpha == 0 || numOfBigAlpha == 0)
        {
            grade += 10;
        }
        else if(numOfSmallAlpha != 0 && numOfBigAlpha != 0)
        {
            grade += 25;
        }
        if(numOfDigit == 1)
        {
            grade += 10;
        }
        else if(numOfDigit > 1)
        {
            grade += 25;
        }
        if(numOfOther == 1)
        {
            grade += 10;
        }
        else if(numOfOther > 1)
        {
            grade += 25;
        }
        if(numOfDigit != 0 && ((numOfSmallAlpha + numOfBigAlpha) != 0))
        {
            grade += 2;
        }
        if(numOfDigit != 0 && ((numOfSmallAlpha + numOfBigAlpha) != 0) && numOfOther != 0)
        {
            grade += 3;
        }
        if(numOfDigit != 0 && numOfSmallAlpha != 0 && numOfBigAlpha != 0 && numOfOther != 0)
        {
            grade += 5;
        }
        if(grade >= 90)
        {
            cout << "VERY_SECURE" << endl;
        }
        else if(grade >= 80)
        {
            cout << "SECURE" << endl;
        }
         else if(grade >= 70)
        {
            cout << "VERY_STRONG" << endl;
        }
         else if(grade >= 60)
        {
            cout << "STRONG" << endl;
        }
         else if(grade >= 50)
        {
            cout << "AVERAGE" << endl;
        }
         else if(grade >= 25)
        {
            cout << "WEAK" << endl;
        }
         else if(grade >= 0)
        {
            cout << "VERY_WEAK" << endl;
        }
    }
}