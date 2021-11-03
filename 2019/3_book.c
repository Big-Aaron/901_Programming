//
// 己知某市有 N 个书店都在销售同样的 M 种书籍，给定 N 个书店 M 种书籍的价格信息，
// 试按下面要求编写程序:
// (1) 分别计算每种书籍的平均价格
// (2) 分别求出每种书籍中价格最高的及最低的价格、对应所在书店的序号以及书籍序号
//
#include <stdio.h>

#define N 3
#define M 4

int main(void) {
    double prices[N][M];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("请输入第%d家书店的第%d本书的价格:\t", i + 1, j + 1);
            scanf("%lf", &prices[i][j]);
        }
        printf("\n");
    }
    for (int j = 0; j < M; ++j) {
        double temp = 0;
        double maxPrice = prices[0][j];
        int imax;
        double minPrice = prices[0][j];
        int imin;
        for (int i = 0; i < N; ++i) {
            temp += prices[i][j];
            if (prices[i][j] > maxPrice) {
                maxPrice = prices[i][j];
                imax = i;
            }
            if (prices[i][j] < minPrice) {
                minPrice = prices[i][j];
                imin = i;
            }
        }
        printf("第%d本书的平均价格为:%lf\n", j + 1, temp / N);
        printf("第%d本书的最高价格为:%lf，所在书店为第%d家\n", j + 1, maxPrice, imax + 1);
        printf("第%d本书的最低价格为:%lf，所在书店为第%d家\n\n", j + 1, minPrice, imin + 1);
    }

}
