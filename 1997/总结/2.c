//
// 该题具有当时的内存不足算力恐惧症
//
#include <stdio.h>

int main() {
    char m, n, x, b;
    x = 0;
    do {
        x++;
        m = 7 * x + 1;
        n = 1;
        b = 0xff;
        while ((m > n) && b) {
            m = m - n;
            if (!(m % 7)) m = (int) (m / 7) * 6;
            else b = 0;
            n++;
        }
    } while (m != n);
    printf("n = %d m=%d\n", n, 7 * x + 1);
}