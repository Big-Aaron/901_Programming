//
// 请编写程序判断一个字符串是否是回文。若是回文，函数返回值为1,否则返回值为0。(回文是顺读和倒读都一样的字符串)。
// 要求:
// (1)编写函数sub()判断一字符串是否为回文。
// (2)在主函数中完成数据的输入与结果的输出。
//

#include <stdio.h>
#include <string.h>

#define MaxSize 10001

int main(void) {
    int sub();
    char str[MaxSize];
    printf("请输入要进行判断的字符串:\t");
    scanf("%s", str);
    if (sub(str) == 1) {
        printf("输入的字符串是回文串");
    } else {
        printf("输入的字符串不是回文串");
    }
}

int sub(char *str) {
    unsigned long len = strlen(str);
    char *p, *q;
    p = str, q = str + len - 1;
    while (p != q) {
        if (*p != *q) {
            return 0;
        }
        p++, q--;
    }
    return 1;
}