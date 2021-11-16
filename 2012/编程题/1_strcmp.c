//
// 程序实现任意两个字符串s1、s2的比较
// 要求:
// (1)字符串的比较写一函数(sub)实现，不得调用标准库函数strcmp;
// (2)在主函数中完成数据的输入与结果的输出。
//

#include <stdio.h>

#define MaxSize 1001

int main(void) {
    int sub();
    char S1[MaxSize];
    char S2[MaxSize];
    printf("请输入字符串S1:\t");
    scanf("%s", S1);
    printf("请输入字符串S2:\t");
    scanf("%s", S2);
    printf("较大的字符串为");
    if (sub(S1, S2) > 0) {
        printf("S1:\t%s", S1);
    } else {
        printf("S2:\t%s", S2);
    }
}

int sub(char *S1, char *S2) {
    char *p = S1;
    char *q = S2;
    while (p || q) {
        if (*p == *q) {
            p++, q++;
            continue;
        } else {
            return *p - *q;
        }
    }
}