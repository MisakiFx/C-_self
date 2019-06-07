/**
 * 数据给相关表类声明
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Table
{
    public:
        Table(int type);
        /**
         * 根据u查找数据
         * str:要查找的数据
         * return:成功返回下标，失败返回-1
         */
        int SearchByU(string str);
        /**
         * 根据h查找数据
         * str:要查找的数据
         * return:成功返回下标，失败返回-1
         */
        int SearchByH(string str);
        /**
         * 根据s查找数据
         * str:要查找的数据
         * return:成功返回下标，失败返回-1
         */
        int SearchByS(string str);
        /**
         * 根据v查找数据
         * str:要查找的数据
         * return:成功返回下标，失败返回-1
         */
        int SearchByV(string str);
        /**
         * 根据t查找数据
         * str:要查找的数据
         * return:成功返回下标，失败返回-1
         */
        int SearchByT(string str);
        /**
         * 根据下表打印元组信息
         * index:下标
         */
        void PrintByIndex(int index);
        /**
         * 打印表的基本信息
         */
        void PrintBaseMessage();
        /**
         * 打印表的所有数据
         */
        void PrintData();
    private:
        double pressure;//压强
        double tSat;    //温度
        vector<string> t;//温度
        vector<string> v;//密度的倒数 / 体积
        vector<string> u;//热力学能
        vector<string> h;//焓
        vector<string> s;//熵
};