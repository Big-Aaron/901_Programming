//
// 简化了题目中的结构体数组，换为int数组
//

#include <stdio.h>

#define SWAP(x, y) do{if(&(x)==&(y))break;(x)=(x)+(y);(y)=(x)-(y);(x)=(x)-(y);}while(0);

void shakeSort(int *r, int n) {
    int t, l, h;
    l = 0, h = n - 1, t = 0;
    do {
        for (int i = l; i < h; ++i) {
            if (r[i] > r[i + 1]) {
                SWAP(r[i], r[i + 1]);
                t = i;
            }
        }
        h = t - 1;//此时 t 为最后一次 swap 后较小的值，下标比 t 大的，都已经有序了。
        for (int i = h; i >= l; --i) {
            if (r[i] > r[i + 1]) {
                SWAP(r[i], r[i + 1]);
                t = i;
            }
        }
        l = t + 1;//此时 t 为最后一次 swap 后较小的值，下标比 t 小的，都已经有序了。
    } while (l <= h);
}

int main() {
    int r[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    shakeSort(r, sizeof(r) / sizeof(int));
    for (int i = 0; i < sizeof(r) / sizeof(int); ++i) {
        printf("%d\t", r[i]);
    }
}