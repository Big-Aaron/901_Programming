//
// 输入一行字符，分别统计出英文字母、空格、数字和其他字符的个数
//

// 本题暗藏杀机

#include <stdio.h>

#define MaxSize 1001

int main(void) {

    printf("请输入字符串:\t");

    int letterNum = 0;
    int spaceNum = 0;
    int figuresNum = 0;
    int otherNum = 0;
    int c;
    c = getchar();
    while (c!='\n'){
        if (c <= '9' && c >= '0') {
            figuresNum++;
        } else if (c == ' ') {
            spaceNum++;
        } else if (c <= 'z' && c>= 'a' || c <= 'Z' && c >= 'A') {
            letterNum++;
        } else {
            otherNum++;
        }
        c = getchar();
    }
//    char str[MaxSize];
//    // 使用fgets函数会将符号'\'识别为'\\'，一个字符变两个
//    fgets(str, MaxSize, stdin);
//    // 使用scanf函数无法识别空格，scanf会把空格当做发送缓冲区数据的指令
//    scanf("%s", str);
//    // 使用gets虽然可以识别，但该函数没有缓冲区，容易内存泄漏，不太安全
//    gets(str);
//    char *p = str;
//    while (*p != '\0') {
//        if (*p <= '9' && *p >= '0') {
//            figuresNum++;
//        } else if (*p == ' ') {
//            spaceNum++;
//        } else if (*p <= 'z' && *p >= 'a' || *p <= 'Z' && *p >= 'A') {
//            letterNum++;
//        } else {
//            otherNum++;
//        }
//        p++;
//    }
    printf("该字符串中英文字母个数:%d 空格个数:%d 数字个数:%d 其他字符个数%d", letterNum, spaceNum, figuresNum, otherNum);
}