#include <iostream>
using namespace std;
/** 模拟游戏中私聊的函数 */
//负责字符串的拼接 
//第一个参数是聊天对象的名称，第二个参数是聊天内容
//返回按某格式拼接聊天信息后的字符串 
string chatTo(const string& toName,const string& content)
{
	string msg = "★你悄悄的对[" + toName + "]说：" + content;
	return msg; 
}
string chatFrom(const string& fromName,const string& content)
{
	string msg = "★[" + fromName + "]悄悄的对你说：" + content;
	return msg;
}
int main()
{
	cout << "请输入对方的名称：";
	string toName, content;
	getline(cin,toName);
	cout << "请输入发送给对方的聊天信息：";
	getline(cin, content);
	string chatMsg = chatTo(toName,content);
	cout << chatMsg << endl; 
	string fromContent = "老子是你爹！";
	string fromMsg = chatFrom(toName,fromContent);
	cout << fromMsg << endl;
	
}
