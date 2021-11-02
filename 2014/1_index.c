//
// 编写一个函数，函数首部为 int index(char *str,char t)，用来计算字符t在str中第一次出现的位置。
// 如 str 为 “abec” ，t为'c'，则返回3。如果没有找到该宇符，则返回-1。
//

#include <stdio.h>

#define MaxSize 1001

int index(char *str, char t) {
    char *p = str;
    while (*p != t && *p != '\0') {
        p++;
    }
    if (*p == t) {
        return (int) (p - str);
    } else {
        return -1;
    }
}

int main(void) {
    char str[MaxSize];
    char t;
    int c;
    printf("请输入字符串:\t");
    scanf("%s", str);
    while ((c = getchar()) != EOF && c != '\n');
    printf("请输入所查找字符:\t");
    scanf("%c", &t);
    c=index(str, t);
    if(c!=-1){
        printf("字符 %c 首次出现在字符串 %s 的位置为 %d\n",t,str,c);
    } else{
        printf("没有找到");
    }
}