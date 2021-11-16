//
// 磁盘当前目录下存在文件 c1.txt,其中存放了一段英文文字。
// 请编程实现将 c1.txt 中英文文字全部转换为大写字母，并保存到 c2.txt 文件中。
// 要求：
// c2.txt文件的前面保存的是 c1.txt 文件中的原始文字，后面紧跟着的是转换后的文字。
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define pwd1 "./c1.txt"
#define pwd2 "./c2.txt"

void create_db() {
    FILE *fp1;
    if ((fp1 = fopen(pwd1, "w")) == NULL) {
        fprintf(stderr, "con open file %s", pwd1);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 50; ++i) {
        fprintf(fp1, "%c", (i + 'A'));
    }
    fclose(fp1);
}

int main(void) {
    create_db();
    FILE *fp1, *fp2;
    if ((fp1 = fopen(pwd1, "r")) == NULL) {
        fprintf(stderr, "con open file %s", pwd1);
        exit(EXIT_FAILURE);
    }
    if ((fp2 = fopen(pwd2, "w")) == NULL) {
        fprintf(stderr, "con open file %s", pwd2);
        exit(EXIT_FAILURE);
    }
    char temp;
    while (!feof(fp1)) {
        fscanf(fp1, "%c", &temp);
        fprintf(fp2, "%c", temp);
    }
    fseek(fp1, 0L, SEEK_SET);
    while (!feof(fp1)) {
        fscanf(fp1, "%c", &temp);
        temp = toupper(temp);
        fprintf(fp2, "%c", temp);
    }
    fclose(fp1), fclose(fp2);
}