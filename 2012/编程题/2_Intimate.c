
// 如果整数A的全部因子(包括1,不包括A本身)之和等于B,且整数B的全部因子(包括1,不包括B本身)之和等于A，
// 则将整数A和B称为为亲密数对。编程求5000以内的全部亲密数对。

#include <stdio.h>

int factorsSum(int n) {
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        if (n % i == 0)sum += i;
    }
    return sum;
}

int main(void) {
    for (int i = 0; i < 5001; ++i) {
        int sum = factorsSum(i);
        if (i == factorsSum(sum))printf("%d\t%d\n", sum, i);
    }
}