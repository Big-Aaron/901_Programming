//
// 编写一个函数insert(s1,s2,ch),实现在字符串s1中的指定字符ch位置处插入字符串s2。
//

// 在读取用户输入的字符串时:
// 使用scanf函数字符串结尾以\0结束
// 使用fgets函数字符串结尾以\n\0结束

#include <stdio.h>

#define MaxSize 30

int main(void) {
    void insert(char *, char *, char ch);
    char s1[MaxSize];
    char s2[MaxSize];
    char ch;
    int c;
    printf("请输入第一个字符串:\t");
    scanf("%s", s1);
    while ((c = getchar()) != EOF && c != '\n');
    printf("请输入第二个字符串:\t");
    scanf("%s", s2);
    while ((c = getchar()) != EOF && c != '\n');
    printf("请输入插入位置的字符:\t");
    scanf("%c", &ch);
    insert(s1, s2, ch);
    printf("插入后的字符串为:\t");
    printf("%s\n", s1);
}

void insert(char *s1, char *s2, char ch) {
    char *p = s1;
    char *q = s1;
    char *r = s2;
    int s2Len = 0;
    while (*p != ch) {
        p++;
    }
    while (*q != '\0') {
        q++;
    }
    while (*r != '\0') {
        s2Len++;
        r++;
    }
    while (q != p) {
        *(q + s2Len) = *(q);
        q--;
    }
    q++;
    r = s2;
    while (*r != '\0') {
        *q = *r;
        r++;
        q++;
    }
}