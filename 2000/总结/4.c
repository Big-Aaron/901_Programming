#include <stdio.h>

#define MAXN 100
int a[MAXN];
int test_data[] = {3, 4, 5};

void rd(int n, int k) {
    int j, i;
    for (j = n; j >= 1; --j) {
        a[k] = j;
        if (n == a[k] && a[k] <= a[k - 1]) {
            printf("%d = %d", a[0], a[1]);
            for (i = 2; i <= k; ++i) {
                printf(" + %d", a[i]);
            }
            printf("\n");
        } else {
            rd(n - a[k], k + 1);
        }
    }
}

int main() {
    for (int i = 0; i < sizeof(test_data) / sizeof(int); ++i) {
        a[0] = test_data[i];
        rd(test_data[i], 1);
    }
}


