//
// 起泡排序是把大的元素向下移，也可以将小的元素向上移，
// 请给出下移和上移过程交替的起泡排序程序，即双向起泡排序程序(一趟冒泡排序排好一个大数和一个小数)。
// 假设元素采用顺序存储。
// 要求:
// (1)编写函数sort()实现排序。
// (2)在主函数中完成数据的输入与结果的输出。
//

#include <stdio.h>

#define SWAP(x, y) do{if(&(x)==&(y))break;(x)=(x)+(y);(y)=(x)-(y);(x)=(x)-(y);}while(0);

int main(void) {
    void sort();
    int N;
    printf("请输入数组元素的总个数:\t");
    scanf("%d", &N);
    int num[N];
    for (int i = 0; i < N; ++i) {
        printf("请输入数组的第%2d个元素:\t", i + 1);
        scanf("%d", &num[i]);
    }
    sort(num, N);
    printf("排序后:\n");
    for (int i = 0; i < N; ++i) {
        printf("%d\t", num[i]);
    }
}

void sort(int *num, int N) {
    int left, right;
    left = 0, right = N - 1;
    while (left <= right) {
        for (int i = left; i < right; ++i) {
            if (num[i] > num[i + 1]) {
                SWAP(num[i], num[i + 1]);
            }
        }
        right--;
        for (int i = right; i > left; --i) {
            if (num[i] < num[i - 1]) {
                SWAP(num[i], num[i - 1]);
            }
        }
        left++;
    }
}