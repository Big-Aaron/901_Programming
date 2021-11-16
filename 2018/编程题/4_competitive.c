//
// 某企业竞争力评价综合指数，使用了多个评价因素，包括:财务效益指标，企业资产运营状况，企业债务水平，企业发展潜力四个内容。
// 现有一个文本文件分别保存了 100 个企业的评价因素数据。数据样例如下:
// 企业名称          财务效益指标     企业资产运营状况     企业债务水平    企业发展潜力
// 第一创新资本          0.8              0.7             0.6            0.4
// 大澳风光财富          0.3              0.6             0.9            0.2
// 请编程实现企业竞争力的排名。期中:
// 企业竞争力 = 0.5 * 财务效益指标 + 0.3 * 企业资产运营状况 + 0.1 *企业债务水平 + 0.1 * 企业发展潜力
//
// 1)打开文本文件，并以结构体形式保存从文本文件中读取到的数据
// 2)计算这 100 个企业的竞争力，并排名
// 3)将企业名称和竞争力排名结果保存到新的文本文件中
//

#include <stdio.h>
#include <stdlib.h>

#define N 100
#define MaxSize 27
#define pwdIn "./company.txt"
#define pwdOut "./power.txt"

//#define test

typedef struct Company {
    char name[MaxSize];
    double dBenefit;
    double dOperation;
    double dDebt;
    double dPotential;
    double dPower;
} Company;

int cmpfun(const void *a, const void *b) {
    return ((Company *) a)->dPower < ((Company *) b)->dPower ? 1 : -1;
}

#ifdef test

void create_db() {
    FILE *fin;
    if ((fin = fopen(pwdIn, "w")) == NULL) {
        fprintf(stderr, "can not open file %s", pwdIn);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < N; ++i) {
        fprintf(fin, "%s\t", "L");
        fprintf(fin, "%.1lf\t", i / 10.0);
        fprintf(fin, "%.1lf\t", i / 10.0);
        fprintf(fin, "%.1lf\t", i / 10.0);
        fprintf(fin, "%.1lf\n", i / 10.0);
    }
    fclose(fin);
}

#endif

int main() {
#ifdef test
    create_db();
#endif
    FILE *fin, *fout;
    if ((fin = fopen(pwdIn, "r")) == NULL) {
        fprintf(stderr, "can not open file %s", pwdIn);
        exit(EXIT_FAILURE);
    }
    if ((fout = fopen(pwdOut, "w")) == NULL) {
        fprintf(stderr, "can not open file %s", pwdOut);
        exit(EXIT_FAILURE);
    }

    Company companys[N];

    for (int i = 0; i < N; ++i) {
        fscanf(fin, "%s", companys[i].name);
        fscanf(fin, "%lf", &companys[i].dBenefit);
        fscanf(fin, "%lf", &companys[i].dOperation);
        fscanf(fin, "%lf", &companys[i].dDebt);
        fscanf(fin, "%lf", &companys[i].dPotential);
        companys[i].dPower = 0.5 * companys[i].dBenefit + 0.3 * companys[i].dOperation + 0.1 * companys[i].dDebt +
                             0.1 * companys[i].dPotential;
    }

    qsort(companys, N, sizeof(Company), cmpfun);

    for (int i = 0; i < N; ++i) {
        fprintf(fout, "%s\t", companys[i].name);
        fprintf(fout, "%.1lf\t", companys[i].dBenefit);
        fprintf(fout, "%.1lf\t", companys[i].dOperation);
        fprintf(fout, "%.1lf\t", companys[i].dDebt);
        fprintf(fout, "%.1lf\t", companys[i].dPotential);
        fprintf(fout, "%.1lf\n", companys[i].dPower);
    }

    fclose(fin), fclose(fout);
}

