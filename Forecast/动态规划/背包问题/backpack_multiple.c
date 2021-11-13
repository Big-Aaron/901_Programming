#include <stdio.h>
#include <string.h>

int weight[] = {1, 3, 4};// 物品重量
int value[] = {15, 20, 30};// 物品价值
int num[] = {2, 3, 2};// 物品数量
int bagWeight = 10;// 背包容量

#define MAX(x, y) (x) > (y) ? (x) : (y);

void test_1_wei_bag_problem() {

    int num_of_goods = 7;

    int dp[bagWeight + 1];// 一维滚动数组

    // 初始化
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < num_of_goods; i++) { // 遍历物品,从物品 0 开始
        for (int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量，从后往前
            for (int k = 1; k <= num[i] && (j - k * weight[i]) >= 0; ++k) {// 遍历相同的物品
                dp[j] = MAX(dp[j], dp[j - k * weight[i]] + k * value[i]);
            }

        }
    }
    printf("最大价值为:%d\n", dp[bagWeight]);
}

int main() {
    test_1_wei_bag_problem();
}
