//
// 用一元人民币兑换成1分、2分和5分硬币，共有多少种不同的兑换方法。
//

#include <stdio.h>

int main(void) {
    int sum = 100;
    int counter = 0;
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 50; ++j) {
            for (int k = 1; k <= 20; ++k) {
                if (i * 1 + j * 2 + k * 5 == sum) {
                    //printf("%d %d %d\n", i, j, k);
                    counter++;
                }
            }
        }
    }
    printf("共有多少种 %d \n", counter);
}