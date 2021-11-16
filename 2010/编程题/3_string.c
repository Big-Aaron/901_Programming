//
// 将两个字符串s和t的前n个字符拼接成新的字符串，结果存放s中。如果s或t中字符串的长度不足n,按实际长度处理。
// 要求:
// ①自定义一个函数完成字符串的拼接;
// ②在主函数中完成输入和输出;
// ③不能使用string.h中的任何字符串操作函数。
//

#include <stdio.h>

int main(void) {
    void scpy();
    int n;
    int c;
    printf("请输入需要拼接字符串的个数:\t");
    scanf("%d", &n);
    while ((c = getchar()) != EOF && c != '\n');
    char s[n * 2 + 1];
    char t[n * 2 + 1];
    printf("请输入第一个字符串:\t");
    fgets(s, n * 2 + 1, stdin);
    printf("请输入第二个字符串:\t");
    fgets(t, n * 2 + 1, stdin);
    scpy(s, t, n);
    printf("拼接后的字符串为:\n%s", s);
}

void scpy(char *s, char *t, int n) {
    int i = 0;
    while (s[i] != '\n' && i < n)i++;
    int j = 0;
    while (t[j] != '\n' && j < n) {
        s[i++] = t[j++];
    }
}