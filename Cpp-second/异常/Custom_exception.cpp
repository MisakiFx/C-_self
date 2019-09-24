#include <iostream>
#include <string>
// 服务器开发中通常使用的异常继承体系
class Exception
{
protected:
    std::string _errmsg;
    int _id; 
    //list<StackInfo> _traceStack;    
    // ... 
};
class SqlException : public Exception
{
};

class CacheException : public Exception
{
};

class HttpServerException : public Exception
{
};

int main()
{
    try
    {
        // server.Start();
        // 抛出对象都是派生类对象
    }
    catch (const Exception &e) // 这里捕获父类对象就可以
    {
    }
    catch (...)
    {
        std::cout << "Unkown Exception" << std::endl;
    }
    return 0;
    }
}
