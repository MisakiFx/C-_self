#include <iostream>
using namespace std;
class FileSystem
{
public:
    size_t numDisks() const
    {
        return _disks;
    }
private:
    size_t _disks = 5;
};
FileSystem& tfs();