#include <iostream>
#include <map>
#include <unordered_map>
int main()
{
    std::map<int, int> m;
    m.insert(std::make_pair(1, 1));
    m.insert(std::make_pair(4, 4));
    m.insert(std::make_pair(2, 2));
    m.insert(std::make_pair(4, 4));
    m.insert(std::make_pair(6, 6));
    std::cout << "map:" << std::endl;
    for(auto e : m)
    {
        std::cout << e.first << " " << e.second << std::endl;
    }
    std::unordered_map<int, int> um;
    um.insert(std::make_pair(1, 1));
    um.insert(std::make_pair(4, 4));
    um.insert(std::make_pair(2, 2));
    um.insert(std::make_pair(4, 4));
    um.insert(std::make_pair(6, 6));
    std::cout << "unordered-map:" << std::endl;
    for(auto e : um)
    {
        std::cout << e.first << " " << e.second << std::endl;
    }

}