#include <stdio.h>

int main() {
    char s = '\097';
    char c = '7';
    if (s == c)printf("yes");
    else printf("no");
}
// 编译器提示 if 语句 always false 但 输出为 true；