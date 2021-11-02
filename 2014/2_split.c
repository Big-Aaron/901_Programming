//
// 编写一个函数，函数首部为int split(int n, int *a, int *b),
// 对于正整数n, 将其分解为任意两个素数之和a和b,若无法分解，则返回0，若可以分解，则返回1。
// 其中主函数如下:
//
//void main() {
//    int n, a, b;
//
//    scanf("%d", &n);
//
//    if (split(n, &a, &b) == 1)
//        printf("%d,%d", a, b);
//    else
//        printf("no results!");
//}


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


int split(int n, int *a, int *b) {
    for (int i = 2; i < n; ++i) {
        if (IsPrime(i) && IsPrime(n - i)) {
            *a = i, *b = n - i;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int n, a, b;

    scanf("%d", &n);

    if (split(n, &a, &b) == 1)
        printf("%d,%d", a, b);
    else
        printf("no results!");
}
