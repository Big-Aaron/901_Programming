//
// 含 N 个元素的整形数组 a ,选任一元素 a[m] , 将其他元素重新排列，
// 使得 a[i]<=a[m],a[j]>=a[m],(i<m,j>m) 注: 不得对数组a重新排序。
// 例如: a数组元素为 65 70 75 80 85 60 55 50 45
// 若选择 a[0]=65 ,则结果为60 45 50 55 65 85 80 75 70
//

// 功能上实现了题目要求，但是不知道用例的实现方法是啥？

#include <stdio.h>
//#define test
#define run
int main(void) {
    void quick();
#ifdef run
    int N, m;
    printf("请输入数组的元素个数:\t");
    scanf("%d", &N);
    printf("请输入选择排列元素序号:\t");
    scanf("%d", &m);
    int a[N];
    for (int i = 0; i < N; ++i) {
        printf("第%d个元素为:\t", i + 1);
        scanf("%d", a + i);
    }
#endif
#ifdef test
    int N = 9;
    int a[9] = {65, 70, 75, 80, 85, 60, 55, 50, 45};
    int m = 0;
#endif
    quick(a, N, m);
    for (int i = 0; i < N; ++i) {
        printf("%d\t", a[i]);
    }
}

void quick(int *a, int N, int m) {
    int *p, *q;
    int temp;
    p = &a[0];
    q = &a[N - 1];
    temp = a[m];
    while (p < q) {
        while (q > p && *q >= temp)q--;
        *p = *q;
        while (p < q && *p < temp)p++;
        *q = *p;
    }
    *p = temp;
}