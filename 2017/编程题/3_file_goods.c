//
// 某仓库库存商品清单中包含当前的库存商品的信息。
// 信息包括：商品编号，商品名称，商品产地、商品进货价格，商品存量。
// 请编程：输出商品占用资金数量最小和最大的商品信息。占用资金数量=商品存量*商品进货价格。
// 要求：
// 设计一个计算和查找占用最小及最大资金数量的函数
// 并在主函数中调用它。
//

#include <stdio.h>
#include <stdlib.h>

#define pwd "./info.dat"

#define MaxSize 21
#define MaxNum 100

//#define test

typedef struct Good {
    unsigned long num;
    char name[MaxSize];
    char addr[MaxSize];
    double price;
    unsigned int stock;
} Good;
#ifdef test

void create_db() {
    FILE *fp;
    if ((fp = fopen(pwd, "w")) == NULL) {
        fprintf(stderr, "can not open file %s\n", pwd);
        exit(EXIT_FAILURE);
    }
    Good goods[Maxnum];
    for (int i = 0; i < Maxnum; ++i) {
        goods[i].num = i;
        goods[i].name[0] = 'L';
        goods[i].name[1] = '\0';
        goods[i].addr[0] = 'B';
        goods[i].addr[1] = '\0';
        goods[i].price = i;
        goods[i].stock = Maxnum - i;
    }
    fwrite(goods, Maxnum, sizeof(Good), fp);
    fclose(fp);
}

#endif

void find(Good goods[MaxNum]) {
    double min;
    int imin;
    double max;
    int imax;
    double temp;
    min = max = goods[0].price * goods[0].stock;
    for (int i = 0; i < MaxNum; ++i) {
        temp = goods[i].price * goods[i].stock;
        if (temp > max) {
            max = temp;
            imax = i;
        }
        if (temp < min) {
            min = temp;
            imin = i;
        };
    }
    printf("占用资金数量最大的为:\n");
    printf("商品编号:%lu 商品名称:%s 商品产地:%s 商品进货价格:%lf 商品存量:%u\n", goods[imax].num, goods[imax].name, goods[imax].addr,
           goods[imax].price,
           goods[imax].stock);

    printf("占用资金数量最小的为:\n");
    printf("商品编号:%lu 商品名称:%s 商品产地:%s 商品进货价格:%lf 商品存量:%u\n", goods[imin].num, goods[imin].name, goods[imin].addr,
           goods[imin].price,
           goods[imin].stock);

}


int main(void) {

#ifdef test
    create_db();
#endif
    FILE *fp;
    if ((fp = fopen(pwd, "r")) == NULL) {
        fprintf(stderr, "can not open file %s\n", pwd);
        exit(EXIT_FAILURE);
    }
    Good goods[MaxNum];
    fread(goods, MaxNum, sizeof(Good), fp);
    fclose(fp);

    find(goods);

}
