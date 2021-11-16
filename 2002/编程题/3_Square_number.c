//
// 将 1,2,3,4,5,6,7,8,9 这九个数字分成三组，每个数字只能用一次，
// 即每组三个数不许有重复数字，也不许同其他组的三个数字重复，
// 要求每组中的三位数都组成一个平方数。
//
#include <math.h>
#include <stdio.h>

// 暴力穷举法
void func() {
    int nums[20] = {0};
    int index = 0;
    int used[10] = {0};
    int flag = 1;
    for (int i = 123; i <= 987; ++i) {
        if ((int) sqrt(i) * (int) sqrt(i) == i) {
            nums[index++] = i;
        }
    }
    for (int i = 0; i < index; ++i) {
        for (int j = i + 1; j < index; ++j) {
            for (int k = j + 1; k < index; ++k) {

                used[nums[i] / 100]++;
                used[nums[i] % 10]++;
                used[(nums[i] / 10) % 10]++;

                used[nums[j] / 100]++;
                used[nums[j] % 10]++;
                used[(nums[j] / 10) % 10]++;

                used[nums[k] / 100]++;
                used[nums[k] % 10]++;
                used[(nums[k] / 10) % 10]++;

                for (int l = 1; l < 10; ++l) {
                    if (used[l] == 0) {
                        flag = 0;
                    }
                    used[l] = 0;
                }
                if (flag == 1) {
                    printf("%d %d %d", nums[i], nums[j], nums[k]);
                }
                flag = 1;
            }
        }
    }
}

int Nums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int Used[9] = {0};
int ans[100] = {0};
int ansSize = 0;

void dfs(int nums[9], int used[9], int square) {
    if (square > 999)return;

    if ((int) sqrt(square) * (int) sqrt(square) == square && square != 0 && square > 100) {
        ans[ansSize++] = square;//找到全排列中的平方数
    }
    for (int i = 0; i < 9; ++i) {
        if (used[i] != 0)continue;
        used[i]++;
        square = square * 10 + Nums[i];
        dfs(nums, used, square);
        used[i]--;
        square = square / 10;

    }
}

int main() {

    //暴力穷举法
    //func();

    // 回溯排列法
    dfs(Nums, Used, 0);
    for (int i = 0; i < ansSize; ++i) {
        printf("%d\t", ans[i]);//暂时没有想到更好的去重方案。
    }
}