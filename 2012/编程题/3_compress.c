//
// 程序实现将无序整数数组压缩成有序数组，
// 即去掉数组中重复出现的元素，并将不重复的元素按以小到大的顺序存放数组前k个元素中，其中k是并将不重复的元素个数。
// 例：原数组：4 2 7 10 4 7 1 6 2
// 压缩后：1 2 4 6 7 10 (k=6)
// 要求：本题在原数组上进行压缩和排序，不得引进另一个数组。

#include <stdio.h>
#include <stdlib.h>

#define test
//#define ren

int cmpfun(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main(void) {
    int compress();

#ifdef test
    int A[] = {4, 2, 7, 7, 10, 4, 7, 5, 4, 2, 9, 3, 1, 6, 2};
    int N = sizeof(A) / sizeof(int);
#endif
#ifdef run
    int N;
    printf("请输入数组元素的个数:\t");
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; ++i) {
        printf("请输入第%d个数组元素:\t", i + 1);
        scanf("%d", &A[i]);
    }
#endif
    qsort(A, N, sizeof(int), cmpfun);
    N = compress(A, N);

    printf("压缩排序后:\n");
    for (int i = 0; i < N; ++i) {
        printf("%d\t", A[i]);
    }
}

int compress(int *A, int N) {
    int k = 1;
    for (int i = 1; i < N; ++i) {
        if (A[i] == A[i - k]) {
            k++;
            continue;
        }
        A[i - k + 1] = A[i];
    }
    return N - k + 1;
}