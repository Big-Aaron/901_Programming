//
// 一个数如果恰好等于它的因子之和，这个数就称为 “完数”。
// 例如 6=1+2+3
// 编程:找出 1000 以内的所有完数。
//
#include <stdio.h>

int factorSum(int n) {
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    if (sum == n) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    for (int i = 0; i < 1001; ++i) {
        if(factorSum(i))printf("%-3d ",i);
    }
}
