//
// 如果一个数列中的任意一段(至少是两个元素)的各个元素均相同，我们称之为等值数列段。
// 等值数列段中元素的个数叫等值数列段长度。
// 现有100个元素组成的整数数列A，求A中长度最大的所有等值数列段的首末位置,并输出该等值数列段的首末位置。
// 如果没有等值数列段，则输出结束标志(not have).
// 要求:所有运算均应在原数组上进行，不得引进第二个数组。
//

// 题目中没有说出现相同最长等值段时怎么处理，所以默认取最开始的那段
#include <stdio.h>

//#define test

#define run

int main(void) {
    void segment();
#ifdef run
    int N;
    printf("请输入数列长度:\t");
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; ++i) {
        printf("请输入第%d个元素值:\t",i+1);
        scanf("%d",A+i);
    }
#endif
#ifdef test
    int N = 10;
    int A[10] = {1, 1, 1, 2, 2, 2, 2, 2, 5, 5};
#endif
    segment(A, N);
}

void segment(int *A, int N) {
    int max, start, end;
    int tempmax, p, q;
    max = -1;
    tempmax = 1;
    for (p = 0, q = 1; q < N;) {
        if (A[p] == A[q]) {
            tempmax++;
            q++;
        } else {
            if (max < tempmax) {
                max = tempmax;
                start = p;
                end = q - 1;
                tempmax = 1;
            }
            p = q;
            q++;
        }
    }
    if (max < 2) {
        printf("not have");
    } else {
        printf("最长等值段为:%d,首位置为%d,末位置为%d", max, start + 1, end + 1);
    }
}

