//
// 有一种特殊4位数，它的千位数上的数加个位数上的数等于百位数上的数加十位数上的数。
// 例如:数字1346，1+6=3+4, 则该数满足条件。而数字1235,1+5<>2+3，则该数不满足条件。
// 请编程完成如下的任务:
// 1)计算所有这种特殊的4位数的数量。
// 2)将这些4位数保存到数组中，并进行从小到大的排序。
//

#include <stdio.h>
#include <stdlib.h>

int cmpfun(const void *a, const void *b) {
    return *(int *) a > *(int *) b ? 1 : -1;
}

int main(void) {
    int nums[10000 - 1000];
    int j = 0;
    int thousand, hundred, ten, single;
    for (int i = 1000; i < 10000; ++i) {
        thousand = (i / 1000) % 10;
        hundred = (i / 100) % 10;
        ten = (i / 10) % 10;
        single = (i / 1) % 10;
        if (thousand + single == hundred + ten) {
//            printf("%5d", i);
            nums[j++] = i;
        }
    }
    printf("满足条件的4位数有 %d个\n", j);
    qsort(nums, j, sizeof(int), cmpfun);
    printf("\n");
    for (int i = 0; i < j; ++i) {
        printf("%5d", nums[i]);
    }
}