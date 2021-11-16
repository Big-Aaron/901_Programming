//
// 编写程序，生成如下序列的前n项。
// 1,2,1,2,3,2,1,2,3,4,3,2,1,2,3,4,5,4,3,2,1,2,...
//
#include <stdio.h>

int main() {
    int isEnought();
    int n;
    printf("输入所需的前项数:");
    scanf("%d", &n);
    int counter = 0;
        for (int i = 2; ; ++i) {
            int j;
            if (counter>=n)break;
            for (j = 1; j < i; ++j) {
                if(isEnought(n)) { printf("%d\t", j); } else{printf("\b...");return 0;}
            }
            for (; j >1 ; --j) {
                if(isEnought(n)) { printf("%d\t", j); } else{printf("\b...");return 0;}
            }
        }
}

int isEnought(int n){
    static int counter=0;
    counter++;
    if(counter<=n){
        return 1;
    } else{
        return 0;
    }
}