//
// 编写一个程序，用来统计由英文文字组成的文本文件中专有名词的个数(判断方式:单词中全都是大写字母认为是专有名词)。
// 例如英文件名称abc.txt。其中的内容为“FORBES The CEO of Boloco's Social Media Strategy”。
// 这段文字有两个专有名词"FORBES""CEO"，
// 请实现如下的功能:
// 1)设计函数，实现专有名词数量的计算 要求:以文本文件名做为函数参数
// 2)在上述函数中，输出各个专有名词。
// 3)设计主函数，输入文件名，调用上述函数并输出专有名词的数量。
//

// 比我想象中的麻烦，要考虑去重

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 27
#define MaxNouns 1001
char *properNoun[MaxNouns];

int cmpfun(const void *a, const void *b) {
    return strcmp(*(char **) a, *(char **) b);
}

void proper(char *pwd) {

    FILE *fp;
    if ((fp = fopen(pwd, "r")) == NULL) {
        fprintf(stderr, "con open file %s", pwd);
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while (!feof(fp)) {
        char *temp = (char *) malloc(sizeof(char) * MaxSize);
        fscanf(fp, "%s", temp);
        char *p = temp;
        while (*p != '\0') {
            if (*p <= 'Z' && *p >= 'A') {
                p++;
                continue;
            }
            break;
        }
        if (*p == '\0') {
            properNoun[i++] = temp;
        }
    }
    // 排序为了去重
    qsort(properNoun, i, sizeof(char *), cmpfun);

    // 去重
    int k = 1;
    for (int j = 1; j < i; ++j) {
        if (strcmp(properNoun[j], properNoun[j - k]) == 0) {
            k++;
            continue;
        }
        strcpy(properNoun[j - k + 1], properNoun[j]);
    }

    printf("一共有专属名词 %d 个\n", i - k + 1);
    for (int j = 0; j < i - k + 1; ++j) {
        printf("%s\n", properNoun[j]);
    }
}

int main(void) {
    char pwd[MaxSize];
    printf("请输入文件地址:\t");
    scanf("%s", pwd);
    proper(pwd);

}