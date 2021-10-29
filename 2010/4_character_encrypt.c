//
// 从键盘输入若干行字符(每行长度不等)，输入后把它们进行加密存储到一个磁盘文件中，再从该文件中读入加密字符进行解密，在显示屏上输出。
// 加密规则是:非字母字符不变，字母字符的第i个字母变成第(26-i+1)个字母
// 要求:
// ①自定义函数完成字符的加密和解密;
// ②在主函数中完成输入、存储、读取和输出;
// ③以字符#作为输入结束。
//

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 1001

int main(void) {
    void encrypt_decrypt();
    FILE *fp;
    if ((fp = fopen("./encrypt.dat", "w")) == NULL) {
        printf("can not open file");
        exit(1);
    }

    char str[MaxSize];
    printf("请输入字符串或输入#结束输入:\t");
    fgets(str, MaxSize, stdin);
    while (str[0] != '#') {
        encrypt_decrypt(str);
        fprintf(fp, "%s", str);
        printf("请输入字符串或输入#结束输入:\t");
        fgets(str, MaxSize, stdin);
    }
    fclose(fp);
    if ((fp = fopen("./encrypt.dat", "r")) == NULL) {
        printf("can not open file");
        exit(1);
    }
    while (!feof(fp)) {
        fscanf(fp, "%s\n", str);
        encrypt_decrypt(str);
        printf("%s\n", str);
    }
    fclose(fp);
}

int isLetter(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= 'a' && c <= 'z') {
        return 2;
    }
    return 0;
}

void encrypt_decrypt(char *str) {
    char *p = str;
    while (*p != '\n') {
        switch (isLetter(*p)) {
            case 1:
                (*p) = (char) ('Z' - ((*p) - 'A'));
                break;
            case 2:
                (*p) = (char) ('z' - ((*p) - 'a'));
                break;
            default:
                break;
        }
        p++;
    }
}
