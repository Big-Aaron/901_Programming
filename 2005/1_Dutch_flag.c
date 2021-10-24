//
// 设计一个程序，重排N个整数的顺序，使所有负数都在非负数之前。
// 要求:(1) 不要对这N个整数排序，否则不给分。
//     (2) 程序应是非递归的。
//

#include<stdio.h>

#define SWAP(x, y) do{if(&(x)==&(y))break;(x)=(x)+(y);(y)=(x)-(y);(x)=(x)-(y);}while(0);
//#define test
#define run

int main() {
    void FlagSort();
#ifdef run
    int N;
    printf("请输入数组长度:\t");
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; ++i) {
        printf("请输入第%d个元素:\t",i+1);
        scanf("%d", a + i);

    }
#endif
#ifdef test
    int a[] = {-1, -2, -3, 4, 0, 6, -7, -8, 9, 0};
    int N = sizeof(a) / sizeof(int);
#endif
    FlagSort(a, N - 1);
    for (int i = 0; i < N; i++) {
        printf("%d\t", a[i]);
    }

}

void FlagSort(int a[], int len) {
//将元素值按负、零、正的顺序进行排列
    int i = 0, j = 0, k = len;//i指向负数,j指向0，k指向正数
    int sign;
    while (j <= k) {
        sign = (a[j] == 0) ? 0 : (a[j] > 0) ? 1 : -1;//判断当前元素的正负性
        switch (sign) {
            case -1:
                SWAP(a[i], a[j]);
                i++, j++;
                break;
            case 0:
                j++;
                break;
            case 1:
                SWAP(a[j], a[k]);
                k--;
                break;
            default:
                printf("数组中有非法元素\n");
                break;
        }
    }
}
