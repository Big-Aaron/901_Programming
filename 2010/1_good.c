//
// 有10种商品，每种商品的数据包括:品名、单价和出厂日期，从键盘输入10种商品的数据，统计价格在30元以上的商品数目，并输出它们的全部信息。
// 要求:
// ①在主函数中输入、统计和输出;
// ②用指向结构体变量的指针进行处理。
//
#include <stdio.h>
#include <stdlib.h>

#define N 10
#define MaxSize 20
typedef struct Good {
    char name[MaxSize];
    float price;
    char date[MaxSize];
} Good;

int main(void) {
    Good *pgoods[N];
    int c;
    for (int i = 0; i < N; ++i) {
        Good *good = (Good *) malloc(sizeof(Good));
        printf("请输入第%d种商品的名称:\t", i + 1);
        fgets(good[i].name, MaxSize, stdin);
        printf("请输入第%d种商品的单价:\t", i + 1);
        scanf("%f", &good[i].price);
        while ((c = getchar()) != EOF && c != '\n');
        printf("请输入第%d种商品的出厂日期:\t", i + 1);
        fgets(good[i].date, MaxSize, stdin);
        pgoods[i] = good;
    }
    for (int i = 0; i < N; ++i) {
        if (pgoods[i]->price > 30.f) {
            printf("%s\t%f\t%s\n", pgoods[i]->name, pgoods[i]->price, pgoods[i]->date);
        }
    }
}
