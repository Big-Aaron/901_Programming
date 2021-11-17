#include <stdio.h>

int main() {
    char a = 010, b = 10;
    printf("%d\n",  a ^ b >> 2);//a ^ (b >> 2)
    printf("%d\n",  a ^ (b >> 2));
}