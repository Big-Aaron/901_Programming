//
// 已知在C盘根目录下存有文本文件“fle1.txt",编程统计文件 “file1.txt" 中每个字母字符和每个数字字符出现的频率，
// 在屏幕上显示统计结果，并将统计结果写入磁盘文件“file2.dat"中。
//

#include <stdio.h>
#include <stdlib.h>

int num[10];
char capital[26];
char lowercase[26];
int sum;

int distinction(char c) {
    sum++;
    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= 'a' && c <= 'z') {
        return 2;
    } else if (c <= '9' && c >= '0') {
        return 3;
    } else {
        sum--;
        return 0;
    }
}

int main() {
    FILE *fp;
    if ((fp = fopen("./file1.txt", "r")) == NULL) {
        fprintf(stderr, "can open file");
        exit(EXIT_FAILURE);
    }
    int ch;
    while (!feof(fp)) {
        ch = fgetc(fp);
        switch (distinction((char) ch)) {
            case 1:
                capital[ch - 'A']++;
                break;
            case 2:
                lowercase[ch - 'a']++;
                break;
            case 3:
                num[ch - '0']++;
                break;
            default:
                break;
        }
    }
    fclose(fp);
    if ((fp = fopen("./file2.txt", "w")) == NULL) {
        printf("can not open file");
        exit(1);
    }
    fprintf(fp, "字母\t");
    printf("字母\t");
    for (int i = 0; i < 26; ++i) {
        fprintf(fp, "%8c\t", 'a' + i);
        printf("%8c\t", 'a' + i);
    }
    fprintf(fp, "\n频率\t");
    printf("\n频率\t");
    for (int i = 0; i < 26; ++i) {
        fprintf(fp, "%8.6lf\t", (double) lowercase[i] / sum);
        printf("%8.6lf\t", (double) lowercase[i] / sum);
    }
    fprintf(fp, "\n\n");
    printf("\n\n");

    fprintf(fp, "字母\t");
    printf("字母\t");
    for (int i = 0; i < 26; ++i) {
        fprintf(fp, "%8c\t", 'A' + i);
        printf("%8c\t", 'A' + i);
    }
    fprintf(fp, "\n频率\t");
    printf("\n频率\t");
    for (int i = 0; i < 26; ++i) {
        fprintf(fp, "%8.6lf\t", (double) capital[i] / sum);
        printf("%8.6lf\t", (double) capital[i] / sum);
    }
    fprintf(fp, "\n\n");
    printf("\n\n");

    fprintf(fp, "数字\t");
    printf("数字\t");
    for (int i = 0; i < 10; ++i) {
        fprintf(fp, "%8c\t", '0' + i);
        printf("%8c\t", '0' + i);
    }
    fprintf(fp, "\n频率\t");
    printf("\n频率\t");
    for (int i = 0; i < 10; ++i) {
        fprintf(fp, "%8.6lf\t", (double) num[i] / sum);
        printf("%8.6lf\t", (double) num[i] / sum);
    }
    fprintf(fp, "\n\n");
    printf("\n\n");

}
