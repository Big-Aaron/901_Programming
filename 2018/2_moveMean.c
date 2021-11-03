//
// 某 x 日指数移动平均的计算方法如下:用前 x 日的指数平均做为当前指数的数值。如果前 x 日数据不足，就用前一日指数的数据代替。
// 例如:
// 指数序列为:
// 10 20 30 40 50 60
// 其3日指数移动平均是:
// 0 (数据不足) 10 (数据不足) 20 (数据不定) 20 ((10+20+30)/3) 30 40
// 请编程实现:当用户输入指数序列，以及 x 日等数据后，完成指数移动平均的计算，并将原始数据和指数移动平均数据输出显示。
// 要求:
// 使用如下定义的函数 int moveMean(double *pData, int nDay)实现该程序

#include <stdio.h>

#define N 7

int moveMean(double *pData, int nDay);

int main(void) {
    double pData[N];
    int nDay;
    for (int i = 0; i < N; ++i) {
        printf("请输入第%d日的指数:\t", i + 1);
        scanf("%lf", &pData[i]);
    }
    printf("请输入用前几日的指数平均:\t");
    scanf("%d", &nDay);

    printf("原指数序列为:\n");
    for (int i = 0; i < N; ++i) {
        printf("%.2lf\t", pData[i]);
    }

    moveMean(pData, nDay);

    printf("\n%d指数序列为:\n", nDay);
    for (int i = 0; i < N; ++i) {
        printf("%.2lf\t", pData[i]);
    }
}

int moveMean(double *pData, int nDay) {
    for (int i = N - 1; i > 0; --i) {
        if (i < nDay) {
            pData[i] = pData[i - 1];
            continue;
        }
        double temp = 0;
        for (int j = i - 1; j >= i - nDay; --j) {
            temp += pData[j];
        }
        pData[i] = temp / nDay;
    }
    pData[0] = 0;
}