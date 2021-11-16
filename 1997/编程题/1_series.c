//
// 有数的集合 { 2^m, 3^n | m>=1, n>=1 }从两个数列{2^m},{3^n} 中取出小的数进入新的数列，
// 使它们按升序排列，新数列不用数组存放，而直接打印输出
//

#include <stdio.h>

int main() {
    int m, n;
    printf("请输入m 与 n 的值:\t");
    scanf("%d %d", &m, &n);

    int x, y;
    x = 2, y = 3;

    int X, Y;
    X = x, Y = y;
    int i, j;
    for (i = 0, j = 0; i <= m && j <= n;) {
        if (X < Y) {
            printf("%d\t", X);
            X = X * x;
            i++;
        } else {
            printf("%d\t", Y);
            Y = Y * y;
            j++;
        }
    }
    if (i > m) {
        while (j <= n) {
            printf("%d\t", Y);
            Y = Y * y;
            j++;
        }
    } else {
        while (i <= m) {
            printf("%d\t", X);
            X = X * x;
            i++;
        }
    }
}