//
// 某函数f(x)的值由如下等式计算
// f(x)= 1 - X^2/(2!) + X^4/(4!) + ... +(-1)^k*X^(2K)/(2k!) + ... ,其中k=0,1,2 …
// 请编写程序计算前 f(x) 函数的前 20 项的值，x 为任意输入的数据。

#include <stdio.h>

#define N 20

long double fun(int x) {
    long double sum = 1;
    long double power = 1;
    long double factorial = 1;
    long double flag = -1;
    for (int i = 2; i < 2 * N; i += 2) {
        power *= x * x;
        factorial *= i * (i - 1);
        sum += flag * (power / factorial);
        flag *= -1;
    }
    return sum;
}

int main() {
    int x;
    printf("请输入 x 的值:\t");
    scanf("%d", &x);
    printf("f(x) = %Lf", fun(x));

}