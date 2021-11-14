//
// 设有某种原料总数量为 a。用于生产 N 种产品。若分配数量 xi 用于生产第 i 种产品，其收益为 g(xi)。
// 问应如何分配，才能使生产 N 种产品的总收入最大？
//

// 按照离散型资源分配处理

#include <stdio.h>

//#define test
#define run

int main(void) {

#ifdef test
    int N = 3;
    int M = 5;
    int profit[3][5] = {{0, 4, 7, 10, 13},
                        {0, 5, 9, 11, 13},
                        {0, 4, 6, 11, 14}};
#endif

#ifdef run
    int N;
    printf("要生产多少种产品:\t");
    scanf("%d", &N);
    int M;
    printf("有多少种分配方案:\t");
    scanf("%d", &M);

    int profit[N][M];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("生产第 %d 种商品的第 %d 方案所得利润为:\t", i + 1, j + 1);
            scanf("%d", &profit[i][j]);
        }
    }
#endif

    int dp[M];// 一维滚动数组

    // dp数组初始化
    for (int i = 0; i < M; ++i) {
        dp[i] = profit[0][i];
    }

    for (int i = 1; i < N; ++i) {// 先遍历产品
        for (int j = M; j >= 0; --j) {// 再遍历利润,逆推法
            int max = 0;
            for (int k = j; k >= 0; --k) {// 寻找最大利润
                int temp = dp[k] + profit[i][j - k];
                if (temp > max) max = temp;
            }
            dp[j] = max;
        }
    }

    printf("最大利润为:%d\t", dp[M - 1]);
}