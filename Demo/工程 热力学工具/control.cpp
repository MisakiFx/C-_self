/**
 * 控制函数的定义
 */
#include "control.h"
#define TABLENUM 8
//数据=初始化函数
vector<Table> tables;
void Init()
{
    for(int i = 1; i <= TABLENUM; i++)
    {
        tables.push_back(Table(i));
    }
}
void SearchByT()
{
    cout << "please input data of T:";
    string str;
    cin >> str;
    int count = 0;
    for(int i = 0; i < tables.size(); i++)
    {
        int index = tables[i].SearchByT(str);
        if(index != -1)
        {
            tables[i].PrintByIndex(index);
            cout << endl;
            count++;
        }
    }   
    if(count == 0)
    {
        cout << "No data!" << endl;
    }
}
void SearchByV()
{
    
    cout << "please input data of v:";
    string str;
    cin >> str;
    int count = 0;
    for(int i = 0; i < tables.size(); i++)
    {
        int index = tables[i].SearchByV(str);
        if(index != -1)
        {
            tables[i].PrintByIndex(index);
            cout << endl;
            count++;
        }
    }   
    if(count == 0)
    {
        cout << "No data!" << endl;
    }
}
void SearchByU()
{
    
    cout << "please input data of u:";
    string str;
    cin >> str;
    int count = 0;
    for(int i = 0; i < tables.size(); i++)
    {
        int index = tables[i].SearchByU(str);
        if(index != -1)
        {
            tables[i].PrintByIndex(index);
            cout << endl;
            count++;
        }
    }   
    if(count == 0)
    {
        cout << "No data!" << endl;
    }
}
void SearchByH()
{
    
    cout << "please input data of h:";
    string str;
    cin >> str;
    int count = 0;
    for(int i = 0; i < tables.size(); i++)
    {
        int index = tables[i].SearchByH(str);
        if(index != -1)
        {
            tables[i].PrintByIndex(index);
            cout << endl;
            count++;
        }
    }   
    if(count == 0)
    {
        cout << "No data!" << endl;
    }
}
void SearchByS()
{
    
    cout << "please input data of s:";
    string str;
    cin >> str;
    int count = 0;
    for(int i = 0; i < tables.size(); i++)
    {
        int index = tables[i].SearchByS(str);
        if(index != -1)
        {
            tables[i].PrintByIndex(index);
            cout << endl;
            count++;
        }
    }   
    if(count == 0)
    {
        cout << "No data!" << endl;
    }
}
void SearchTable()
{
    cout << "table list:" << endl;
    for(int i = 0; i < tables.size(); i++)
    {
        cout << (i + 1) << ".";
        tables[i].PrintBaseMessage();
    }
    int index = -1;
    cout << "please input table index:";
    cin >> index;
    if(index > 8 || index < 1)
    {
        cout << "Input error!" << endl;
        return;
    }
    tables[index - 1].PrintData();
}