#include <stdio.h>
#include <string.h>

int weight[] = {1, 3, 4};// 物品重量
int value[] = {15, 20, 30};// 物品价值
int bagWeight = 4;// 背包容量

#define MAX(x, y) (x) > (y) ? (x) : (y);

void test_1_wei_bag_problem() {

    int num_of_goods = sizeof(weight) / sizeof(int);

    int dp[bagWeight + 1];// 二维数组

    // 初始化
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < num_of_goods; i++) { // 遍历物品,从物品 0 开始
        for (int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量，从后往前
            dp[j] = MAX(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    printf("最大价值为:%d\n", dp[bagWeight]);
}

int main() {
    test_1_wei_bag_problem();
}
