//
// 对一组字符串按从小到大的顺序进行排序。
// 要求:
// ①在主函数输入和输出;
// ②用一个函数排序;
// ③用指向指针的指针的方法进行处理。
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 1001

int cmpstr(const void *a, const void *b) {
    return strcmp(*(char **) a, *(char **) b);
}

int main(void) {
    int len;
    int c;
    printf("请输入字符串的个数:\t");
    scanf("%d", &len);
    char *strings[len];
    while ((c = getchar()) != EOF && c != '\n');
    for (int i = 0; i < len; ++i) {
        char *string = (char *) malloc(sizeof(char) * MaxSize);
        printf("请输入第%d个字符串:\t", i + 1);
        fgets(string, MaxSize, stdin);
        strings[i] = string;
    }
    qsort(strings, len, sizeof(char *), cmpstr);
    printf("排序后的字符串为:\n");
    for (int i = 0; i < len; ++i) {
        printf("%s", strings[i]);
    }
}

