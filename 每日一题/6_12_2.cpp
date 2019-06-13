#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int num = 0;
    string str;
    while(scanf("%d", &num) == 1)
    {
        cin >> str;
        int head = 1;//当前视图的第一个
        int pos = 0;//当前视图中所选中的下标
        if(num <= 4)
        {
            for(int i = 0; i < str.size(); i++)
            {
                if(str[i] == 'U')
                {
                    if(pos == 0)
                    {
                        pos = num - 1;
                    }
                    else
                    {
                        pos--;
                    }
                }
                if(str[i] == 'D')
                {
                    if(pos == num - 1)
                    {
                        pos = 0;
                    }
                    else
                    {
                        pos++;
                    }
                }
            }
        }
        else
        {
            for(int i = 0; i < str.size(); i++)
            {
                if(str[i] == 'U')
                {
                    if(head == 1 && pos == 0)
                    {
                        head = num - 3;
                        pos = 3;
                    }
                    else
                    {
                        if(pos > 0)
                        {
                             pos--;
                        }
                         else
                        {
                            head--;
                        }
                    }
                }
                else
                {
                    if(head == num - 3 && pos == 3)
                    {
                        head = 1;
                        pos = 0;
                    }
                    else
                    {
                        if(pos < 3)
                        {
                            pos++;
                        }
                        else
                        {
                            head++;
                        }
                    }
                }
            }
        }
        vector<int> output;
        if(num <= 4)
        {
            for(int i = head; i <= num; i++)
            {
                output.push_back(i);
            }
        }
        else
        {
            for(int i = head; i < head + 4; i++)
            {
                output.push_back(i);
            }
        }
        for(int i = 0; i < output.size() - 1; i++)
        {
            cout << output[i] << " ";
        }
        cout << output[output.size() - 1] << endl;
        cout << (head + pos) << endl;
    }
}
