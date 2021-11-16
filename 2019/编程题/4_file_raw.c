//
// 某公司原材料采购清单中包含当前正在采购的所有原材料信息。
// 每条信息包括：材料编号、材料名称、材料单价、采购数量、送货日期。
// 试按下面要求编写程序:
// (1) 定义包含原材料信息的结构体 raw
// (2) 编写函数 get_raw_info， 实现包含 10 条原材料信息的结构体数组输入;
// (3) 编写函数 sort_raw，实现结构体数组按采购总价(采购总价=材料单价*采购数量)从大到小的排序;
//(4） 在主函数中调用 get_raw_info 和 sort_raw，并进一步实现将采购总价最大的前 5 项原材料信息写入D盘下的文件save.dat.
//

#include <stdio.h>
#include <stdlib.h>

#define N 10
#define M 5
#define MaxSize 27
#define pwd "save.dat"
typedef struct raw {
    char no[MaxSize];
    char name[MaxSize];
    double price;
    int num;
    char date[MaxSize];
} raw;

raw raws[N];

void get_raw_info() {
    int c;
    for (int i = 0; i < N; ++i) {
        printf("请输入第%d个材料的信息:\n", i + 1);
        printf("材料编号为:\t");
        fgets(raws[i].no, MaxSize, stdin);
        printf("材料名称为:\t");
        fgets(raws[i].name, MaxSize, stdin);
        printf("材料单价为:\t");
        scanf("%lf", &(raws[i].price));
        printf("材料数量为:\t");
        scanf("%d", &(raws[i].num));
        while ((c = getchar()) != EOF && c != '\n');// 陷阱
        printf("送货日期为:\t");
        fgets(raws[i].date, MaxSize, stdin);
    }
}

int cmpfun(const void *a, const void *b) {
    return (((raw *) a)->num) * (((raw *) a)->price) < (((raw *) b)->num) * (((raw *) b)->price) ? 1 : -1;
}

void sort_raw() {
    qsort(raws, N, sizeof(raw), cmpfun);
}

int main() {
    FILE *fp;
    if ((fp = fopen(pwd, "w")) == NULL) {
        fprintf(stderr, "can open file %s", pwd);
        exit(EXIT_FAILURE);
    }
    get_raw_info();
    sort_raw();
    fwrite(raws, sizeof(raw), M, fp);
    fclose(fp);
}