#include <stdio.h>
#include <math.h>

int maxProfit(const int *prices, int pricesSize) {

    if (pricesSize == 0)return 0;// 鲁棒性

    int dp[pricesSize][2];// 二维dp数组

    dp[0][0] = -prices[0], dp[0][1] = 0;// 初始化第一天数据

    for (int i = 1; i < pricesSize; ++i) {
        dp[i][0] = (int) fmax(-prices[i], dp[i - 1][0]);
        dp[i][1] = (int) fmax(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[pricesSize - 1][1];// 买股票就一定比不买股票挣得多，因为 famx 函数已经保证了只要买就挣钱。
}

int maxProfit2(const int *prices, int pricesSize) {

    if (pricesSize == 0)return 0;// 鲁棒性

    int dp[2][2];// 二维dp滚动数组

    dp[0][0] = -prices[0], dp[0][1] = 0;// 初始化第一天数据

    for (int i = 1; i < pricesSize; ++i) {
        dp[i % 2][0] = (int) fmax(-prices[i], dp[(i - 1) % 2][0]);
        dp[i % 2][1] = (int) fmax(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i]);
    }
    return dp[(pricesSize - 1) % 2][1];// 买股票就一定比不买股票挣得多，因为 famx 函数已经保证了只要买就挣钱。
}

int main() {
    int pricesSize;
    printf("数组元素个数为:\t");
    scanf("%d", &pricesSize);
    int prices[pricesSize];
    for (int i = 0; i < pricesSize; ++i) {
        printf("第 %d 天的股票价格是:\t", i + 1);
        scanf("%d", &prices[i]);
    }
    printf("最大利润为:%d\n", maxProfit(prices, pricesSize));
    printf("最大利润为:%d\n", maxProfit2(prices, pricesSize));
}