#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    void replaceSpace(char *str, int length)
    {
        int oldLength = 0, newLength = 0, spaceCount = 0;
        for (int i = 0; str[i] != '\0'; i++)
        {
            oldLength++;
            if (str[i] == ' ')
            {
                spaceCount++;
            }
        }
        newLength = oldLength + 2 * spaceCount;
        if (newLength > length)
        {
            return;
        }
        while (oldLength >= 0 && newLength > oldLength)
        {
            if (str[oldLength] != ' ')
            {
                str[newLength] = str[oldLength];
                newLength--;
            }
            else
            {
                str[newLength] = '0';
                str[newLength - 1] = '2';
                str[newLength - 2] = '%';
                newLength -= 3;
            }
            oldLength--;
        }
    }
};
int main()
{
    Solution sol;
    char str[20] = "1 2 3 ";
    sol.replaceSpace(str, 19);
    cout << str << endl;
}