//
// 已知 C:\book\bk_list.dat 文件中存有多种图书信息，每种图书信息包含二个内容：书名和库存量。
// 请编程通过检查全部库存量，在C盘book目录下建立一个新的文件：bk_re.dat，
// 它包括所有库存量小于 30 的图书名称和库存量，并在屏幕上是示所有库存量小于 30 的图书名称及库存量。
// 要求:
// (1)编一个函数实现检查库存量，建立新文件bk_re.dat;
// (2)在主函数中输出结果。
//

#include <stdio.h>
#include <stdlib.h>

#define pwdIn "./bk_list.dat"
#define pwdOut "./bk_re.dat"
#define MaxSize 20

#define test
typedef struct Book {
    char name[MaxSize];
    int inventory;
} Book;
#ifdef test

void create_db() {
    FILE *fp;
    if ((fp = fopen(pwdIn, "w")) == NULL) {
        printf("can not open file");
        exit(1);
    }
    for (int i = 0; i < 10; ++i) {
        fprintf(fp, "%c %d\n", (char) ('A' + i), i * 6);
    }
    fclose(fp);
}

#endif

int main(void) {
#ifdef test
    create_db();
#endif
    FILE *fin, *fout;
    if ((fin = fopen(pwdIn, "r")) == NULL) {
        printf("can not open file");
        exit(1);
    }
    if ((fout = fopen(pwdOut, "w")) == NULL) {
        printf("can not open file");
        exit(1);
    }
    Book book;
    while (!feof(fin)) {
        fscanf(fin, "%s", book.name);
        fscanf(fin, "%d", &(book.inventory));
        if (book.inventory < 30) {
            printf("%s %d\n", book.name, book.inventory);
            fprintf(fout, "%s %d\n", book.name, book.inventory);
        }
    }
    fclose(fin), fclose(fout);
}