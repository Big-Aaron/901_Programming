//
// 统计一个字符串中字母、数字和空格的个数。
// 要求:
//      ①在主函数中输入和输出;
//      ②用一个函数统计;
//      ③用函数指针调用被调函数。
//

#include <stdio.h>
#include <string.h>

#define MaxSize 1001

int main() {
    void Statistics(const char *, unsigned int, unsigned int *, unsigned int *, unsigned int *);
    void (*pfun)(const char *, unsigned int, unsigned int *, unsigned int *, unsigned int *);
    char string[MaxSize];
    unsigned int numLetter, numFigures, numSpace;
    numFigures = numLetter = numSpace = 0;
    printf("请输入字符串:\t");
    fgets(string,MaxSize,stdin);
    pfun = Statistics;
    pfun(string, strlen(string), &numLetter, &numFigures, &numSpace);
    printf("字符串中字母个数:%u,数字个数:%u,空格个数:%u\n", numLetter, numFigures, numSpace);
}

void Statistics(const char *string, unsigned int len, unsigned int *numLetter, unsigned int *numFigures, unsigned int *numSpace) {
    for (int i = 0; i < len; ++i) {
        if (string[i] <= '9' && string[i] >= '0') {
            (*numFigures)++;
        } else if (string[i] <= 'z' && string[i] >= 'a' || string[i] <= 'Z' && string[i] >= 'A') {
            (*numLetter)++;
        } else if (string[i] == ' ') {
            (*numSpace)++;
        }
    }
}