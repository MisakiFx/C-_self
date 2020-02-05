#include <iostream>

int main()
{
    for(int i = 1; i <= 161; i++)
    {
        int full = i;
        int empty = 0;
        int sum = 0;
        std::cout << "i = " << i << std::endl;
        while(full)
        {
            std::cout << "full = " << full << std::endl;
            std::cout << "empty = " << empty << std::endl;
            sum += full;
            empty += full;
            full = empty / 5;
            empty = empty % 5;
            std::cout << "sum = " << sum << std::endl;
        }
        std::cout << std::endl;
        if(sum >= 161)
        {
            std::cout << i << std::endl;
            break;
        }
    }
}
