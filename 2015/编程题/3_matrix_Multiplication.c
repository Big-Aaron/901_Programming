//
// 请编程实现：两个 m*m 阶矩阵相乘。
// 要求：
// 在主函数中进行输入、调用矩阵乘法函数完成两个矩阵相乘，并在主函数内输出结果；
// 两数实现短阵相乘
//
#include <stdio.h>

#define M 3
int MatrixA[M][M];
int MatrixB[M][M];
int MatrixC[M][M];

void MatrixMultiplication() {

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < M; ++k) {
                MatrixC[i][j] += MatrixA[i][k] * MatrixB[j][k];
            }
        }
    }

}

int main(void) {
    printf("请输入矩阵A:\n");
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("请输入矩阵A的第%d行第%d列的元素值:\t", i + 1, j + 1);
            scanf("%d", &(MatrixA[i][j]));
        }
    }
    printf("请输入矩阵B:\n");
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("请输入矩阵B的第%d行第%d列的元素值:\t", i + 1, j + 1);
            scanf("%d", &(MatrixB[i][j]));
        }
    }
    MatrixMultiplication();
    printf("矩阵乘法的结果为:\n");
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%d\t", MatrixC[i][j]);
        }
        printf("\n");
    }
}
