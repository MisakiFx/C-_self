#include <iostream>
#include <string>
#include <algorithm>
int main()
{
    std::string s1;
    std::getline(std::cin, s1);
    auto begin = s1.begin();
    auto end = s1.end();
    std::reverse(begin, end);
    auto start = s1.begin();
    auto finish = s1.begin();
    while(*finish)
    {
        while(*finish != ' ' && *finish != '\0')
        {
            finish++;
        }
        auto it1 = start;
        auto it2 = finish;
        std::reverse(it1, it2);
        finish++;
        start = finish;
    }
    std::cout << s1 << std::endl;
}