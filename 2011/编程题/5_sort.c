//
// 按由大到小的顺序对一个含有 N 个整型数据的数组 A[N] 进行排序，
// 利用如下改进的选择排序方法:第一次选出最大者存入A[1],第二次选出最小者存入A[N]，第三次选出次大者存入A[2]，第四次选出次小者存入A[N-1],
// 如此大小交替地选择，直到排序完成。
// 要求:
// ①编写函数sort完成排序;
// ②主函数完成数据的输入与结果的输出
//

#include <stdio.h>

#define SWAP(x, y) do{if(&(x)==&(y))break;(x)=(x)+(y);(y)=(x)-(y);(x)=(x)-(y);}while(0);

int main() {
    void sort();
    int N;
    printf("请输入数组元素的个数:\t");
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; ++i) {
        printf("请输入第%d个元素\t", i + 1);
        scanf("%d", &A[i]);
    }

    sort(A, N);

    printf("排序后:\n");
    for (int i = 0; i < N; ++i) {
        printf("%d\t", A[i]);
    }
}

void sort(int *A, int N) {
    int left = 0;
    int right = N - 1;
    int imax = left;
    int imin = left;
    while (left <= right) {
        for (int i = left; i <= right; ++i) {
            if (A[i] > A[imax])imax = i;
            if (A[i] < A[imin])imin = i;
        }
        SWAP(A[left], A[imax]);
        SWAP(A[right], A[imin]);
        left++, right--;
        imin = left, imax = left;
    }
}