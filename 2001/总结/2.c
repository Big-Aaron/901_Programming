#include <stdio.h>

int j=4;

int f1();

extern int n;

int main(){
    int k,m,j;

    extern int f2();
    k=4;m=3;j=0;
    printf("p1=%d\n",f1(n,m));
    printf("p2=%d\n",f2(k,m));
    printf("p3=%d\n",f1(n,j));
    printf("p4=%d\n",f2(n,j));
    printf("n=%d\n",n);
    printf("j=%d\n",j);
}
int f1(int m,int k){
    int f;
    if(n)n=k*n;
    j=m+j;f=n%j;
    return (f);
}