//
// 输入一个字符串，内有数字和非数字字符，如:AS234fgh456d17968x7654,将其中连续的数字作为一个整体，依次存放到一数组a中，
// 例如234存入a[0], 456存入a[1], ..编程统计其共有整少个整数，并输出这些数。
// 要求:
// ①编写函数完成将字符串中连续的数字作为一个整体，依次存放到一数组a中;
// ②在主函数中完成数据的输入与结果的输出。
//

#include <stdio.h>

#define MaxSize 1001

int main(void) {
    char str[MaxSize];
    int a[MaxSize];
    printf("请输入字符串:\t");
    fgets(str,MaxSize,stdin);
    int i, j;
    int temp;
    temp = i = j = 0;
    while (str[i] != '\0') {
        if (str[i] <= '9' && str[i] >= '0') {
            temp = temp * 10 + (str[i]-'0');
            i++;
        } else {
            if (temp != 0) {
                a[j++] = temp;
            }
            temp = 0;
            i++;
        }
    }
    for (int k = 0; k < j; ++k) {
        printf("%d\t", a[k]);
    }
}

