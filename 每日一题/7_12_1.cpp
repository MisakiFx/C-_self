#include "stdio.h"
double gener(short x) {
    double item = 0.5; double result = item;
    for (short i = 3; i <= x; i++) {
        item /= -i;
        result += item;
    }
    return result;
}
 
int main()
{
    short n;
    while (~scanf("%2hd", &n)) {
        printf("%5.2f%%\n", 100 * gener(n));
    }
    return 0;
}