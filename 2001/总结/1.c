#include <stdio.h>

int main() {
    char *s[6] = {"BGCD", "OFEH", "IJKV", "ALMN", "QXYZ", "PRST"};
    char **p;
    int k;
    p = s;
    for (k = 1; k < 4; ++k) {
        printf("%c", (*p)[k]);// GCD
    }
}