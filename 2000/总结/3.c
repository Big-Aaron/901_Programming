#include <stdio.h>

char *c[] = {"ENTER", "THIRD", "SECOND", "FIRST"};
char **cp[] = {c + 3, c + 2, c + 1, c};
char ***cpp = cp;

int main() {
    printf("%s\n", (*(*(++cpp))));// SECOND
    printf("%s\n", (*(--(*(++cpp)))) + 3);//  ER
    printf("%s\n", (*(cpp[-2])) + 3);// ST
    printf("%s\n", (cpp[-1][-1]) + 1);// HIRD
}