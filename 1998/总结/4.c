#include <stdio.h>

int main() {
    char str1[] = {'a', 'b', 'c', 'd', '\0'};
    char str2[] = {'e', 'f', 'g', 'h', '\0'};
    char str3[] = {'i', 'j', 'k', 'l', '\0'};
    struct sl {
        char *s;
        struct sl *ptr;
    };
    struct sl a[] = {
            str1, a + 1,
            str2, a + 2,
            str3, a
    };
    struct sl *p = a;

    printf("\n");
    for (int i = 0; i < 3; ++i) {
        // 考察这种题，如同求 3*4 阶行列式。
        printf("%s %s %c %s\n", a[i].s, a[i].ptr->s, ++a[i].s[i], ++p++->ptr->s);
        //printf("%p %p\n",a[i].ptr->s,++p++->ptr->s);
    }
}