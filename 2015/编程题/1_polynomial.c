//
// 请编程实现：计算并输出下列多项式值：
// s = 1 + 1/(1+2) + 1/(1+2+3）+...+ 1/（1+2+3...+50）
//

#include <stdio.h>

int main(void) {
    long double s = 0;
    long double temp = 0;
    for (int i = 1; i <= 50; ++i) {
        temp += i;
        s += 1 / temp;
    }
    printf("s = %Lf", s);
}
