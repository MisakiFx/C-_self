//https://www.nowcoder.com/practice/0a92c75f5d6b4db28fcfa3e65e5c9b3f?tpId=49&&tqId=29277&rp=1&ru=/
/**
 * 题目描述
扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A，2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）:) 
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER 
输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如：4 4 4 4-joker JOKER
请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR

基本规则：
（1）输入每手牌可能是个子，对子，顺子（连续5张），三个，炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）
（3）大小规则跟大家平时了解的常见规则相同，个子，对子，三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
（4）输入的两手牌不会出现相等的情况。

答案提示：
（1）除了炸弹和对王之外，其他必须同类型比较。
（2）输入已经保证合法性，不用检查输入是否是合法的牌。
（3）输入的顺子已经经过从小到大排序，因此不用再排序了.
输入描述:
输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如4 4 4 4-joker JOKER。
输出描述:
输出两手牌中较大的那手，不含连接符，扑克牌顺序不变，仍以空格隔开；如果不存在比较关系则输出ERROR。

示例1
输入
4 4 4 4-joker JOKER

输出
joker JOKER
 */
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int NumOfPoker(string str)
//{
//    int count = 1;
//    for(size_t i = 0; i < str.size(); i++)
//    {
//        if(str[i] == ' ')
//        {
//            count++;
//        }
//    }
//    return count;
//}
//int PriceOfPoker(string str)
//{
//    int res = 0;
//    /*
//    if(str == "joker")
//    {
//        res = 14;
//    }
//    if(str == "JOKER")
//    {
//        res = 15;
//        return res;
//    }
//    */
//    if(str[0] == '3')
//    {
//        res = 1;
//    }
//    if(str[0] == '4')
//    {
//        res = 2;
//    }
//    if(str[0] == '5')
//    {
//        res = 3;
//    }
//    if(str[0] == '6')
//    {
//        res = 4;
//    }
//    if(str[0] == '7')
//    {
//        res = 5;
//    }
//    if(str[0] == '8')
//    {
//        res = 6;
//    }
//    if(str[0] == '9')
//    {
//        res = 7;
//    }
//    if(str[0] == '1')
//    {
//        res = 8;
//    }
//    if(str[0] == 'J')
//    {
//        res = 9;
//    }
//    if(str[0] == 'Q')
//    {
//        res = 10;
//    }
//    if(str[0] == 'K')
//    {
//        res = 11;
//    }
//    if(str[0] == 'A')
//    {
//        res = 12;
//    }
//    if(str[0] == '2')
//    {
//        res = 13;
//    }
//    return res;
//}
//int main()
//{
//    string str;
//    while(getline(cin, str))
//    {
//        string player1 = str.substr(0, str.find('-'));//玩家一
//        string player2 = str.substr(str.find('-') + 1);//玩家二
//        //判断胜负
//        if(player1 == "joker JOKER")
//        {
//            cout << player1 << endl;
//        }
//        else if(player2 == "joker JOKER")
//        {
//            cout << player2 << endl;
//        }
//        else if(NumOfPoker(player1) == NumOfPoker(player2))
//        {
//            if(PriceOfPoker(player1) > PriceOfPoker(player2))
//            {
//                cout << player1 << endl;
//            }
//            else
//            {
//                cout << player2 << endl;
//            }
//        }
//        else if(NumOfPoker(player1) == 4)
//        {
//            cout << player1 << endl;
//        }
//        else if(NumOfPoker(player2) == 4)
//        {
//            cout << player2 << endl;
//        }
//        else 
//        {
//            cout << "ERROR" << endl;
//        }
//    }
//
//}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    while(getline(cin, str))
    {
        if(str.find("joker JOKER") != -1)
        {
            cout << "joker JOKER" << endl;
        }
        else
        {
            string player1 = str.substr(0, str.find("-"));
            string player2 = str.substr(str.find("-") + 1);
            int count1 = count(player1.begin(), player1.end(), ' ');
            int count2 = count(player2.begin(), player2.end(), ' ');
            string first1 = player1.substr(0, player1.find(" "));
            string first2 = player2.substr(0, player2.find(" "));
            string judge = "345678910JQKA2jokerJOKER";
            if(count1 == count2)
            {
                if(judge.find(first1) > judge.find(first2))
                {
                    cout << player1 << endl;
                }
                else
                {
                    cout << player2 << endl;
                }
            }
            else
            {
                if(count1 == 3)
                {
                    cout << player1 << endl;
                }
                else if(count2 == 3)
                {
                    cout << player2 << endl;
                }
                else
                {
                    cout << "ERROR" << endl;
                }
            }
        }
    }
}