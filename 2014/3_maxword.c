//
// 编写一个函数，函数首部为void maxword(char *s, char *t),
// 求出两个字符串包含的相同单词(同一字母的大小写视为不同的字符)。规定单词全部由英文字母构成，单词之间由一个或多个空格分隔。
// 其中主函数如下:
//
//#include <string.h>
//
//int main() {
//    char s[] = "This is C programming text";
//    char t[] = "This is a text for C programming";
//    maxword(s, t);
//}

// 实现的算法不好，属于曲线救国
// 重点注意下如何用库函数实现字符串的分割

#include <string.h>
#include <stdio.h>

void maxword(char *s, char *t);

int main() {
    char s[] = "This is C programming text";
    char t[] = "This is a text for C programming";
    maxword(s, t);
}

void maxword(char *s, char *t) {
    char *swords[strlen(s)];
    char *twords[strlen(t)];
    memset(swords, 0, sizeof swords);
    memset(twords, 0, sizeof twords);
    char *p = NULL;
    char *q = NULL;
    int i = 0;
    int j = 0;

    // 对字符串s进行空格分割
    p = strtok(s, " "), swords[i++] = p;
    while (p) {
        p = strtok(NULL, " "), swords[i++] = p;
    }
    // 对字符串t进行空格分割
    q = strtok(t, " "), twords[j++] = q;
    while (q) {
        q = strtok(NULL, " "), twords[j++] = q;
    }
    // 遍历查找
    for (int k = 0; k < i - 1; ++k) {
        for (int l = 0; l < j - 1; ++l) {
            if (strcmp(swords[k], twords[l]) == 0) {
                printf("%s ", swords[k]);
            }
        }
    }
}




