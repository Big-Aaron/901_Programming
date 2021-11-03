//
// 请编程实现对如下序列前 30 项进行求和
// sum = 1 - 1/3! + 1/5! - 1/7! + 1/9! ...
//

#include <stdio.h>

#define N 30

int main(void) {
    double sum = 1;
    double factorial = 1;
    int flag = -1;
    int i = 3;
    for (int j = 1; j < N; ++j, i += 2) {
        factorial *= i * (i - 1);
        sum += flag * (1 / factorial);
    }
    printf("前 %d 项和为: %lf \n", N, sum);
}