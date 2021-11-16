//
// 以下公式近似计算e^x的值。编写程序实现:函数f1计算每项分子的值，函数f2计算每项分母的值,在main函数中计算e^x的近似值
// e^x = 1 + x + x^2/2! + x^3/3! + ... + x^(nmax)/(namx!)
//

#include <stdio.h>

#define nmax 20
int x;

double f1() {
    static double j = 1;
    j *= x;
    return j;
}

double f2() {
    static double i = 1;
    static double s = 1;
    s = s * ++i;
    return s;
}

int main(void) {
    printf("请输入 x 的值:\t");
    scanf("%d", &x);
    double sum = 1 + f1();
    for (int i = 2; i < nmax; ++i) {
        sum += f1() / f2();
    }
    printf("e^%d = %lf", x, sum);
}
