
#define PRINT(x) printf("%d\n",x)

#include <stdio.h>

int main() {
    int x, y, z;
    x = 1;
    y = 1;
    z = 0;
    (x = x) && (y || z);
    PRINT(x);// 1

    // y++ && ++z直接短路
    PRINT(x || (y++ && ++z)); // 1

    PRINT(y);//1
    PRINT(z);// 0
}
