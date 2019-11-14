#include <iostream>
class UnusualAdd {
public:
    int addAB(int A, int B) {
        int carryFlag = A & B;
        carryFlag = carryFlag << 1;
        int res = A ^ B;
        while(carryFlag)
        {
            A = res;
            B = carryFlag;
            res = A ^ B;
            carryFlag = A & B;
            carryFlag = carryFlag << 1;
        }
        return res;
    }
};

int main()
{
    UnusualAdd add;
    std::cout << add.addAB(1, 3) << std::endl;
}