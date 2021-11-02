//
// 设有一个数组a包含count个数，已经按照升序排好。
// 现要求编一函数，函数首部为int arrage(int *a, int count, int n, int m)
// 能够把从指定位置n开始的m个数按照逆序重新排列并输出新的完整数列。若排序完成则返回1,出现错误返回0.
//
// void main()
// {
// int i,a[10]= {0,1,2,3,4,6,7,8,9};
// arrage(a,10,3,5);
// for(i=0;i<10;i++)
// printf("%d ",a[i]);
// }
#include <stdio.h>
#include <stdlib.h>

int cmpfun(const void *a, const void *b) {
    return *(int *) a < *(int *) b ? 1 : -1;
}

int arrage(int *a, int count, int n, int m) {
    qsort(a + n, m, sizeof(int), cmpfun);
}

int main() {
    int i, a[10] = {0, 1, 2, 3, 4, 6, 7, 8, 9};
    arrage(a, 10, 3, 5);
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);
}

