//
// 请编程实现：计算并输出了3到n之问所有素数的平方根之和
//

#include <stdio.h>
#include <math.h>

int IsPrime(int n) {
    for (int i = 2; i <= (int) sqrt(n); ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int n;
    printf("请输出要计算的范围n:\t");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 3; i <= n; ++i) {
        if (IsPrime(i)) {
            sum += i;
        }
    }
    printf("从 3 ~ %d 的所有素数和为 %d \n", n, sum);
}