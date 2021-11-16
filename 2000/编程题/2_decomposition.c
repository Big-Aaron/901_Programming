//
// 将一个偶数分解成两个素数之和，并按下面格式输出结果。如:
// 6=3+3
// 8=5+3
// 10=7+3
// 10=5+5
//

#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    if (n <= 1)return 0;
    for (int i = 2; i <= (int) sqrt(n); ++i) {
        if (n % i == 0)return 0;
    }
    return 1;
}

int main(void) {
    int n;
    int c;
    printf("请输入要分解的偶数或输入 Q 退出:\t");
    while (scanf("%d", &n)) {
        for (int i = 2; i < n / 2 + 1; ++i) {
            if (isPrime(i) && isPrime(n - i)) {
                printf("%d = %d + %d\n", n, i, n - i);
            }
        }
        while ((c = getchar()) != EOF && c != '\n');
        printf("请输入要分解的偶数或输入 Q 退出:\t");
    }

}


