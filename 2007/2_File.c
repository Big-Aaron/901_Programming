//
// 已知 C:\goods\INFO.dat 文件中存有数千种库存商品的信息，
// 每种商品信息含三个内容:物资编号NO、商品名称和库存量NUM。
// 请编程通过检查全部库存量，在C盘goods目录下建立一个新的文件: KK.dat ,
// 它包括所有库存量大于50的商品编号、商品名称和库存量，并在屏幕上显示所有库存量大于50的商品名称。
//

#include <stdio.h>
#include <stdlib.h>
// mac系统没c盘，缩写改了个文件读取和输出地址，./ 即当前可执行程序所在位置
// windows下/应写为转移字符//，即为"C:\\goods\\INFO.dat"
// dat文件具体是文本文件还是二进制文件，看你心情
#define from "./INFO.dat"
#define to "./KK.dat"
#define MaxSize 20
#define test
typedef struct Good {
    unsigned int NO;
    char Name[MaxSize];
    unsigned int NUM;
} Good;

void create_db() {//创造读取的文件
    FILE *fto;
    if ((fto = fopen(from, "w")) == NULL) {
        printf("can not open %s file", from);
        exit(1);
    }
    char *goodNames[] = {"Mac_Pro", "Pro_Display_XDR", "Macbook_Pro", "iPad_Pro", "iPhone_Pro", "Apple_Watch",
                         "Apple_Pencil", "AirPods_Pro", "HomePod", "AirTag"};
    for (int i = 0; i < 10; ++i) {
        fprintf(fto, "%5d\t%-20s\t%5d\n", i, goodNames[i], i * 10);
    }
    fclose(fto);
}

int main() {
#ifdef test
    create_db();
#endif
    // 应该单独写个函数进行读取，满足单一复用原则，但我懒，嘿嘿！
    FILE *fin, *fto;
    if ((fin = fopen(from, "r")) == NULL) {
        printf("can not open %s file", from);
        exit(1);
    }
    if ((fto = fopen(to, "w")) == NULL) {
        printf("can not open %s file", to);
        exit(1);
    }
    Good * good = (Good *) malloc(sizeof(Good));
    while (!feof(fin)) {
        fscanf(fin, "%d", &(good->NO));
        fscanf(fin, "%s", good->Name);
        fscanf(fin, "%d", &(good->NUM));
        if (good->NUM > 50) {
            printf("%s\n", good->Name);
            fprintf(fto, "%5d\t%-20s\t%5d\n", good->NO, good->Name, good->NUM);
        }
    }
    free(good);
    fclose(fin);
    fclose(fto);
}