#include <stdio.h>

// 今年真题中求杨辉三角，我只能说牛逼，但真low
// 动态规划求组合数

int cnm(int m, int n) {

    int dp[n + 1];

    for (int i = 0; i < n + 1; ++i) {
        dp[i] = 1;
    }
    for (int i = 0; i < m - n ; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            dp[j] += dp[j - 1];
        }
    }
    return dp[n];
}


int main() {
    printf("%d", cnm(99, 9));
}