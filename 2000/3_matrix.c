//
// 将自然数按下图所示的次序存到 N * N的二维数组 A 中。(注:下图所示是一个 5 * 5 的二维数组，箭头是提示自然出现的顺序。)
//

//  1  ->   2      9  ->  10      25
//          |      |       |       |
//  4  <-   3      8      11      24
//  |              |       |       |
//  5  ->   6  ->  7      12      23
//                         |       |
// 16  <-  15  <- 14  <-  13      22
//  |                              |
// 17  ->  18  -> 19  ->  20  ->  21

// 画图比写程序还麻烦

#include <stdio.h>

#define N 5

void out(int A[N][N]) {
    for (int k = 0; k < N; ++k) {
        for (int l = 0; l < N; ++l) {
            printf("%3d", A[k][l]);
        }
        printf("\n");
    }
}

int main() {
    int A[N][N] = {0};
    int wal = 1;
    int counter = 1;
    int i, j, k;
    i = 0, j = 0, k = 0;
    while (counter <= N * N) {
        for (k = j; k <= wal; ++k) {
            A[i][k] = counter++;
        }
        out(A);
        j=--k,i++;
        for (k = i; k < i + wal; ++k) {
            A[k][j] = counter++;
        }
        out(A);
        i=--k;j--;
        for (k = j; k >= 0; --k) {
            A[i][k] = counter++;
        }
        out(A);
        j=++k;i++;
        for (k = i; k < i + wal; ++k) {
            A[k][j] = counter++;
        }
        out(A);
        i=--k;j++;
        wal++;
    }
    for (int l = 0; l < N; ++l) {
        for (int m = 0; m < N; ++m) {
            printf("%3d", A[l][m]);
        }
        printf("\n");
    }
}
