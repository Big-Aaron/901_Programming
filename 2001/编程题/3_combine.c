//
// 小刚假期同妈妈一起去书店，他选中了n本书，每本书的单价为：p1,p2,p3...pn元（均为整数）。
// 不巧的是，妈妈只带了s(为整数)元钱，不够买这n本书（即：s<p1+p2+p3+...+pn)。
// 妈妈同意将这s元全部用来买书，
// 也就是小刚要从n本书中选出m本，使得这m本的价格和刚好等于s，即p1+p2+p3+...+pn=s，
// 请你编程序将所有满足这一条件的i1,i2,i3,...im依次打印出来。
//

// 基础的回溯算法，组合问题，题不难，难的是如何用c语言实现。
// c语言没有map或容器或切片，不好进行收集数据，需要熟练掌握指针操作
// 注意指针垃圾回收，c语言需要手动回收垃圾
// 没想到2001年的题就出现了我认为"901"历史上第二"难题"，

#include <stdio.h>

#define MaxSize 10001
int *temp;//当前可能的选择
int tempSize;//当前可能的选择有多少本书
int **ans;//所有的可能性
int ansSize;//有多少种可能性
int *ansColumnSize;//每种可能性中有多少本书
int *prices;//每本书的价格

int main(void) {
    void dfs();
    int n, s;
    printf("请输入你一共选中几本书:\t");
    scanf("%d", &n);
    printf("请输入你一共有多少钱:\t");
    scanf("%d", &s);
    tempSize = ansSize = 0;
    temp = (int *) malloc(sizeof(int) * n);
    ans = (int **) malloc(sizeof(int *) * MaxSize);
    ansColumnSize = (int *) malloc(sizeof(int) * MaxSize);
    prices = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        printf("请输入第%d本书的价钱:\t", i+1);//给用户展示时，序列从1开始
        scanf("%d", prices + i);
    }
    dfs(0, n, s);
    for (int i = 0; i < ansSize; ++i) {
        printf("你可能的选择为：");
        for (int j = 0; j < ansColumnSize[i]; ++j) {
            printf("%d\t", ans[i][j]+1);//给用户展示时，序列从1开始
        }
        free(ans[i]);//回收GC
        printf("\n");
    }
    //进行GC
    free(temp);
    free(ans);
    free(prices);
    free(ansColumnSize);
    return 0;
}

void dfs(int cur, int n, int s) {
    //因为书的价格无序且可能有重复值，所有没有剪枝
    if (s < 0 || cur > n)return;//当钱花完或把所有书遍历完，回溯结束
    if (s == 0) {
        int *tmp = (int *) malloc(sizeof(int) * tempSize);
        for (int i = 0; i < tempSize; ++i) {
            tmp[i] = temp[i];
        }
        ansColumnSize[ansSize] = tempSize;
        ans[ansSize++] = tmp;
        return;
    }
    temp[tempSize++] = cur;
    dfs(cur + 1, n, s - prices[cur]);
    tempSize--;
    dfs(cur + 1, n, s);
}