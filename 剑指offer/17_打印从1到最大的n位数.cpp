#include <iostream>
#include <string>
//只能用字符串来解

//字符串数字+1，如果最高位进位则返回真，表示结束
bool IsOver(std::string& str)
{
    int sum = str[str.size() - 1] - '0';
    sum++;
    if(sum < 10)
    {
        str[str.size() - 1] = sum + '0';
        return false;
    }
    int i = 0;
    for(i = str.size() - 1; i >= 0; i--)
    {
        if(str[i] != '9')
        {
            break;
        }
        else
        {
            str[i] = '0';
        }
        
    }
    if(i < 0)
    {
        return true;
    }
    str[i] = str[i] + 1;
    return false;
}

//打印即可
void Print(const std::string& str)
{
    int i = 0;
    for(i = 0; i < str.size(); i++)
    {
        if(str[i] != '0')
        {
            break;
        }
    }
    if(i == std::string::npos)
    {
        return;
    }
    std::string temp = str.substr(i);
    std::cout << temp << std::endl;
}

void StrSol()
{
    int num;
    while(std::cin >> num)
    {
        if(num <= 0)
        {
            break;
        }
        std::string str(num , '0');
        while(!IsOver(str))
        {
            Print(str);
        }
    }

}


void Recursively(std::string& str, int index)
{
    if(index == str.size() - 1)
    {
        Print(str);
        return;
    }
    for(int i = 0; i < 10; i++)
    {
        str[index + 1] = i + '0';
        Recursively(str, index + 1);
    }
}
//全排列递归解法
void RecursivelySol()
{
    int num;
    while(std::cin >> num)
    {
        if(num <= 0)
        {
            break;
        }
        std::string str(num , '0');
        for(int i = 0; i < 10; i++)
        {
            str[0] = i + '0';
            Recursively(str, 0);
        }
    }
}
int main()
{
    //StrSol();
    RecursivelySol();
}