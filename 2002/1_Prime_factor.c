//
// 编程序输出整数n的全部素数因子。
// 例如：n=120时，素因子为：2,2,2,3,5
//

// 难点在于判断一个数是不是素数

#include <stdio.h>
#include <math.h>

int main(void) {
    void prime();
    int n;
    printf("请输入需要的整数n:\t");
    scanf("%d", &n);
    printf("%d的素数因子有:\t", n);
    prime(n);
}

int IsPrime(int n) {
    if (n == 1 || n == 2)return 1;
    for (int i = 2; i <= (int) sqrt(n); ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void prime(int n) {
    if (n <= 0)return;
    for (int i = 2; i <= n; ++i) {
        if (IsPrime(i) && n % i == 0) {
            printf("\t%d\t",i);
            prime(n/i);
            return;
        }
    }
}