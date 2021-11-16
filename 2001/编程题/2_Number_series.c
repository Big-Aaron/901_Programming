
// 己知某数列前两项为2和3，其后继项根据前面最后两项的乘积，按下列规则生成：
// (1)若乘积为一位数，则该乘积即为数列的后继项。
// (2)若乘积为二位数，则该乘积的十位数字和个位数字依次作为数列的两个后继项。
// 请编程序生成该数列的前 N 项，并求前 N 项的和。
// 要求：生成该数列后继项及求和过程用函数实现，在主函数中调用该函数。

//没什么技巧和难度，考验基础c语言能力

#include <stdio.h>

int main(void) {
    void fun();
    int N;
    int sum = 0;
    printf("请输入需要的数列项数：");
    scanf("%d", &N);
    int result[N];//边长数组
    fun(result, N, sum);
}

void fun(int result[], int N, int sum) {
    if (N >= 2) {
        result[0] = 2;
        result[1] = 3;
        sum = result[0] + result[1];;
        printf("前%d项为\t%d\t%d\t", N, result[0], result[1]);
    } else if (N == 1) {
        result[0] = 2;
        printf("前%d项为\t%d\t,前%d项总和为%d", N, result[0], N, result[0]);
        return;
    } else {
        printf("输入项数不合法");
        return;
    }
    for (int i = 2; i < N; ++i) {
        int temp = result[i - 1] * result[i - 2];
        if (temp % 10 == temp) {//一位数
            result[i] = temp;
            sum += result[i];
            printf("%d\t", result[i]);
        } else {//两位数
            result[i] = temp / 10;
            sum += result[i];
            printf("%d\t", result[i]);
            result[++i] = temp % 10;
            sum += result[i];
            printf("%d\t", result[i]);
        }
    }
    printf("\n前%d项总和为\t%d", N, sum);
}
