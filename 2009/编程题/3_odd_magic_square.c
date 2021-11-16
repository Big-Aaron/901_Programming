//
// 编程实现奇数魔方阵。把整数1到n^2 (n=5为奇数)排成一个n*n方阵，使方阵中的每一行、每一列以及对角线上的数之和都相等。
//

// 最开始以为是回溯算法中的类数独算法然后怎么写怎么不对
// 最后拿纸一模拟，发现是我想太多了。

#include <stdio.h>

#define N 3
int square[N][N];

int main() {
    int index = 1;
    int i = 0;
    int j = N / 2;
    while (index <= N * N) {
        if (square[i][j] != 0) {
            i = (i + 2 + N) % N;
            j = (j - 1 + N) % N;
        }
        square[i][j] = index;
        i = (i - 1 + N) % N;
        j = (j + 1 + N) % N;
        index++;
    }
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            printf("%2d\t", square[i][j]);
        }
        printf("\n");
    }

}
