#include <iostream>
#include <vector>
using namespace std;
class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        for(int i = 0; i < gifts.size(); i++)
        {
            int count = 0;
            for(int j = i; j < gifts.size(); j++)
            {
                if(gifts[j] == gifts[i])
                {
                    cout << gifts[i] << " " << gifts[j] << endl;
                    count++;
                }
            }
            if(count > (n / 2))
            {
                //cout << i << " " << count << endl;
                return gifts[i];
                cout << count << endl;
            }
            else
            {
                int temp = gifts[i];
                i--;
                vector<int>::iterator it = gifts.begin();
                while(it != gifts.end())
                {
                    if(*it == temp)
                    {
                        cout << *it << endl;
                        it = gifts.erase(it);
                    }
                    else
                    {
                        ++it;
                    }
                }
            }
        }
        return 0;
    }
};
int main()
{
    Gift gift;
    vector<int> gifts = {1, 1, 2, 2, 2, 3};
    cout << (gift.getValue(gifts, 6)) << endl;
}