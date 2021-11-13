#include <stdio.h>
#include <string.h>

// 先遍历背包
#define pack
// 先遍历物品
#define good

int weight[] = {1, 3, 4};// 物品重量
int value[] = {15, 20, 30};// 物品价值
int bagWeight = 4;// 背包容量

#define MAX(x, y) (x) > (y) ? (x) : (y);

void test_1_wei_bag_problem() {

    int num_of_goods = sizeof(weight) / sizeof(int);

    int dp[bagWeight + 1];// 一维滚动数组

    // 初始化
    memset(dp, 0, sizeof(dp));
#ifdef good
//先遍历物品
    for (int i = 0; i < num_of_goods; i++) { // 遍历物品,从物品 0 开始
        for (int j = weight[i]; j <= bagWeight; j++) { // 遍历背包容量，从前往后
            dp[j] = MAX(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
#endif
#ifdef pack
//先遍历背包
    for (int j = 0; j <= bagWeight; j++) { //遍历背包容量，从前往后
        for (int i = 0; i < num_of_goods; i++) {// 遍历物品,从物品 0 开始
            if (j >= weight[i]) {
                dp[j] = MAX(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
    }
#endif
    printf("最大价值为:%d\n", dp[bagWeight]);
}

int main() {
    test_1_wei_bag_problem();
}
