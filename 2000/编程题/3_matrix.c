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

// 一开始以为画图比写程序还麻烦，然后...
// 这不是我写的，太丢人了！

#include <stdio.h>

#define N 4

int main() {
    int A[N][N] = {0};
    if (N == 1) {
        A[0][0] = 1;
        goto end;
    }
    if (N == 2) {
        A[0][0] = 1, A[0][1] = 2, A[1][1] = 3, A[1][0] = 4;
        goto end;
    }
    A[0][0] = 1, A[0][1] = 2, A[1][1] = 3, A[1][0] = 4;
    int wal = 2;
    int counter = 5;
    int i, j, k;
    i = 2, j = 0;
    while (counter <= N * N) {
        for (k = j; k <= wal; ++k) {
            A[i][k] = counter++;
            if (counter > N * N) goto end;
        }
        j = --k, i--;
        for (k = i; k >= 0; --k) {
            A[k][j] = counter++;
            if (counter > N * N) goto end;
        }
        i = ++k, j++;
        for (k = j; k <= j; ++k) {
            A[i][k] = counter++;
            if (counter > N * N) goto end;
        }
        j = --k, i++;
        for (k = i; k <= i + wal; ++k) {
            A[k][j] = counter++;
            if (counter > N * N) goto end;
        }
        i = --k, j--;
        for (k = j; k >= 0; --k) {
            A[i][k] = counter++;
            if (counter > N * N) goto end;
        }
        j = ++k, i++;
        wal += 2;
    }
    end:
    for (int l = 0; l < N; ++l) {
        for (int m = 0; m < N; ++m) {
            printf("%3d", A[l][m]);
        }
        printf("\n");
    }
}
