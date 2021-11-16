//
// 在一间房间总共有n个人（下标0～n-1），只能有最后一个人活命。
// 按照如下规则去排除人：
//
// 所有人围成一圈
// 顺时针报数，每次报到q的人将被排除掉
// 被排除掉的人将从房间内被移走
// 然后从被kill掉的下一个人重新报数，继续报q，再清除，直到剩余一人
// 你要做的是：当你在这一群人之间时，你必须选择一个位置以使得你变成那剩余的最后一人，也就是活下来。



#include <stdio.h>

// 递归调用
int joseph(int n, int m) {
    if (n <= 1 || m <= 1)return -1;
    return n == 1 ? n : (joseph(n - 1, m) + m - 1) % n + 1;
}

int joseph2(int n, int m) {
    int s;
    if (n <= 1 || m <= 1)return -1;
    if (m % 2 == 0) s = 0;
    else s = 1;
    for (int i = 3; i <= n; ++i) {
        s = (s + m) % i;
    }
    return s + 1;
}

int main() {
    int m, n;
    printf("请输入一共有多少人？\t");
    scanf("%d", &n);
    printf("准备杀死第几个人？\t");
    scanf("%d", &m);
    printf("第 %d 个人将存活\t", joseph2(n, m));
}