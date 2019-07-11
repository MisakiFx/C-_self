// write your code here cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int num = 0;
    while(cin >> num)
    {
        string result;
        char a = getchar();
        for(int i = 0; i < num; i++)
        {
            string name;
            getline(cin, name);
            //cout << "name: " << name << endl; 
            if(name.find(" ", 0) != -1 || name.find(",", 0) != -1)
            {
                name = "\"" + name + "\"";
            }
            result = result + name;
            //cout << "result: " << result << endl;
            if(i != num - 1)
            {
                result = result + ", ";
            }
        }
        cout << result << endl;
    }
}