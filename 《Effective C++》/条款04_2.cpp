#include <iostream>
#include "FileSystem.h"
using namespace std;
//这里的设计模式十分类似于单例模式
//在函数内部定义静态变量，这样保证在调用函数时一定会先对变量进行初始化
//保证初始化顺序
FileSystem& tfs()
{
    static FileSystem fs;
    return fs;
}