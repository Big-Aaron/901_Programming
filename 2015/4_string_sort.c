//
// 请编程实现对6个从键盘输入的国家名宇进行字典序输出。
// 要求：
// 在主程序中进行输入，调用排序函数并在主函数内输出结果；
// 函数实现排序。
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 6
#define MaxSize 21

int cmpfun(const void *a, const void *b) {
    return strcmp(*(char **) a, *(char **) b);
}


int main(void) {
    char *Countrys[N];
    int c;
    for (int i = 0; i < N; ++i) {
        printf("请输入第%d个字符串:\t", i + 1);
        char *Country = (char *) malloc(sizeof(char) * MaxSize);
        scanf("%s", Country);
        while ((c = getchar()) != EOF && c != '\n');
        Countrys[i] = Country;
    }
    qsort(Countrys, N, sizeof(char *), cmpfun);
    printf("排序后的字符串为:\n");
    for (int i = 0; i < N; ++i) {
        printf("%s\n", Countrys[i]);
    }
}