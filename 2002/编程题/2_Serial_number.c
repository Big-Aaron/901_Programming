//
// 对数组A中的 N (0<N<100)个整数从小到大进行连续编号，
// 要求不能更改数组A中元素的顺序，且相同的整数具有相同的编号。
// 例如：A = (5,3,4,7,3,5,6),则输出:(3,1,2,5,1,3,4)
//

// 眼高手低，暂时没有想到比这复杂度更低的算法

#include <stdio.h>

int main(void) {
    void serial();
    int n;
    printf("要输入的数组长度为:\t");
    scanf("%d", &n);
    int A[7];
    for (int i = 0; i < n; ++i) {
        printf("第%d个元素为:\t", i + 1);
        scanf("%d", A + i);
    }
    serial(A, 7);
}

void serial(int *A, int n) {
    int B[n];
    int min = A[0];
    int max = A[0];
    int Iteration = 1;

    for (int i = 0; i < n; ++i) {
        if (A[i] < min) {
            min = A[i];
        }
        if (A[i] > max) {
            max = A[i];
        }
    }
    for (int i = min; i <= max; ++i, Iteration++) {
        for (int j = 0; j < n; ++j) {
            if (A[j] == i) {
                B[j] = Iteration;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\t", B[i]);
    }

}