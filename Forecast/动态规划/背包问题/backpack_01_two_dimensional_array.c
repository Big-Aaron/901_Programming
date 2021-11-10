#include <stdio.h>
#include <string.h>

int weight[] = {1, 3, 4};// 物品重量
int value[] = {15, 20, 30};// 物品价值
int bagWeight = 4;// 背包容量

#define MAX(x, y) (x) > (y) ? (x) : (y);

void test_2_wei_bag_problem() {

    int num_of_goods = sizeof(weight) / sizeof(int);

    int dp[num_of_goods][bagWeight + 1];// 二维数组

    // 初始化
    memset(dp, 0, sizeof(dp));
    for (int j = weight[0]; j <= bagWeight; j++) {
        dp[0][j] = value[0];
    }

    // weight数组的大小 就是物品个数
    for (int i = 1; i < num_of_goods; i++) { // 遍历物品
        for (int j = 0; j <= bagWeight; j++) { // 遍历背包容量
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = MAX(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }
    printf("最大价值为:%d\n", dp[num_of_goods - 1][bagWeight]);
}

int main() {
    test_2_wei_bag_problem();
}
