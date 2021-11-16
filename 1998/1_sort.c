//
// 编写把一维数组元素中的值按逆序重新效置的程序
//
#include <stdio.h>
#include <stdlib.h>

int cmpfun(const void *a, const void *b) {
    return *(int *) a < *(int *) b ? 1 : -1;
}

int main(void) {
    int len;
    printf("请输入数组的长度:\t");
    scanf("%d", &len);
    int nums[len];
    for (int i = 0; i < len; ++i) {
        printf("请输入第 %d 个数据的值:\t", i + 1);
        scanf("%d", &nums[i]);
    }
    qsort(nums, len, sizeof(int), cmpfun);
    for (int i = 0; i < len; ++i) {
        printf("%d\t", nums[i]);
    }
}
