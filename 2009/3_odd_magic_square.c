//
// 编程实现奇数魔方阵。把整数1到n^2 (n=5为奇数)排成一个n*n方阵，使方阵中的每一行、每一列以及对角线上的数之和都相等。
//

// 最开始以为是回溯算法中的类数独算法然后怎么写怎么不对
// 最后拿纸一模拟，发现是我想太多了。

#include <stdio.h>

#define N 5
int square[N][N] ;
int main() {
    int index = 0;
    int i = 0;
    int j = N / 2;
    int flag = 1;
    while (index < N * N) {
        square[i][j] = index+1;
        if (++index % N == 0) {
            flag *= -1;
            i = i;
            j = (j + 1 + N) % N;
            continue;
        }
        if (flag == 1) {
            i = (i + 1 + N) % N;
            j = (j + 1 + N) % N;
        } else {
            i = (i - 1 + N) % N;
            j = (j - 1 + N) % N;

        }
    }
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            printf("%2d\t", square[i][j]);
        }
        printf("\n");
    }

}
