
// 某人有10张3分的邮票和10张5分的邮票，问使用这些邮票可以组合出多少种不同面值的邮资。
// (例如：1张3分邮票加1张5分邮票可以组成8分的邮资；5张3分的邮票或3张5分的邮票都可以组成同样面值的邮资.)

//  采用暴力法，两层循环，用result数组收集数据，并进行去重后统计总组合

#include "stdio.h"

int main(void) {
    int result[80] = {0};
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            result[i * 3 + j * 5] == 0 ? result[i * 3 + j * 5]++ : result[i * 3 + j * 5];
            //printf("%d\t",i * 3 + j * 5);
        }
        //printf("\n");
    }
    for (int i = 0; i < 80; ++i) {
        if (result[i] != 0) {
            sum++;
        }
    }
    printf("%d\n", sum);//共65种
}