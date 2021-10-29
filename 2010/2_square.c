//
// 将MxN的矩阵转置。
// 要求:
// ①自定义一个函数完成矩阵的转置:
// ②在主函数中输入原矩阵，输出转置后的矩阵;
// ③用指向二维数组的指针进行处理。
//

#include <stdio.h>

#define M 3
#define N 4

int main() {
    void transpose();
    //void transpose2();
    int *p[M];
    int square[M][N];
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("请输入第 %d 行第 %d 列元素值:\t", i + 1, j + 1);
            scanf("%d", &square[i][j]);
        }
        p[i] = square[i];
    }
    //transpose2(p);
    transpose(square);
}

void transpose(int square[M][N]) {
    printf("转置后的矩阵为:\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%d\t", square[j][i]);
        }
        printf("\n");
    }
}
void transpose2(int **square) {
    printf("转置后的矩阵为:\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%d\t", square[j][i]);
        }
        printf("\n");
    }
}