//
//  c语言已经不允许修改字符串常量的元素
//

#include <stdio.h>

char str1[]={'f','o','r','\0'};
char str2[]={'w','h','i','l','e','\0'};
char str3[]={'d','o','_','w','h','i','l','e','\0'};
char str4[]={'s','w','i','t','c','h','\0'};
struct {
    int x;
    char *y;
} *p, A[] = {
        1, str1,
        2, str2,
        3, str3,
        4, str4
};

int main() {
    p = A;
    printf("%d", ++p->x);
    printf("%d", ++(p->x));
    printf("%d", (p++)->x);
    printf("%d", p++->x);
    printf("%c", *p->y);
    printf("%c", *p->y++);
    printf("%c", (*p->y)++);
    printf("%c", *p++->y);
    for (int i = 0; i < 4; ++i) {
        printf("\n%d,%s",A[i].x,A[i].y);
    }

}