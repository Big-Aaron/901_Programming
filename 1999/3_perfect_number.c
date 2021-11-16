//
// 如果一个数恰好等于它的因子之和，则称该数为“完全数”。如: 6的因子是1、2、3，而 6=1+2+3,则6是个“完全数”。试求出1000以内的全部“完全数”
//

#include <stdio.h>

int main(void) {
    for (int i = 2; i <= 1000; ++i) {
        int sum = 0;
        for (int j = 1; j < i; ++j) {
            if (i % j == 0)sum += j;
        }
        if (sum == i)printf("%d\t", i);
    }
}