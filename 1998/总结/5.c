//
// 不明白为什么有 i 这个变量
//

#include <stdio.h>

int search(const int *r, int n, int k) {
    int i, j;
    if (n > 0) {
        j = (k - r[0]) / (r[n - 1] - r[0]);
        j++;
        if (k < r[j]) {
            while ((j > 0) && (k < r[j])) {
                j += (k - r[j]) / (r[n - 1] - r[j]) + 1;
            }
        } else {
            while ((j < n + 1) && (k > r[j])) {
                j += (k - r[j + 1]) / (r[n - 1] - r[j + 1]) + 1;
            }
        }
    } else {
        return -1;
    }

    if (r[j] == k)return j;
    else return -1;
}

int main() {
    int nums[] = {1,3,5,7,9,81,83,85,87,99};
    printf("%d", search(nums, 10, 81));
}