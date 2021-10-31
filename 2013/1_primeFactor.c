//
// 编写一个函数，输出整数m的全部素数因子。例如，m=120时，素数因子为:2,2,2,3,5。
//

// 完美复刻2002年真题,不过要求非递归

#include <stdio.h>
#include <math.h>

int main(void) {
    void prime();
    int n;
    printf("请输入需要的整数:\t");
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
    int i = 2;
    while (n > 0 && i <= n) {
        if (IsPrime(i) && n % i == 0) {
            printf("\t%d\t", i);
            n = n / i;
            i = 2;
            continue;
        }
        i++;
    }
}