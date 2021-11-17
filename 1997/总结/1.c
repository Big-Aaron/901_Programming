//
// 验证c语言只有值参调用
//

#include <stdio.h>

void fun1(int n) {
    n = 6;
}

void fun2(int *p) {
    *p = 7;
}

void fun3(int *p) {
    printf("fun3 收到的指针 p = %p\n", p);
    *p = 8;
    p = (int *) 0xdeadbeef;
    printf("fun3 修改指针后 p = %p\n", p);
}

void fun4(int *a) {
    printf("fun3 收到的指针 &a = %p\n", a);
    *a = 8;
    a = (int *) 0xdeadbeef;
    printf("fun3 修改指针后 &a = %p\n", a);
}

void fun5(int *p) {
    printf("fun5 收到指针的存储地址为 &p = %p\n", &p);
    printf("fun5 收到指针为 p = %p\n", p);
    printf("fun5 收到指针所指向的变量值为 *p = %d\n", *p);
}

int main() {

    int a = 3;
    int *p = &a;
    printf("调用 fun1 之前 a = %d\n", a);
    fun1(a);
    printf("调用 fun1 之后 a = %d\n", a);

    printf("调用 fun2 之前 a = %d\n", a);
    fun2(&a);
    printf("调用 fun2 之后 a = %d\n", a);

    //高能来袭
    printf("调用 fun3 之前 p = %p\n", p);
    fun3(p);
    printf("再次调用 fun3 之后 p = %p\n", p);

    printf("调用 fun4 之前 &a = %p, a = %d\n", &a, a);
    fun4(&a);
    printf("调用 fun4 之后 &a = %p, a = %d\n", &a, a);

    //前方究极高能
    printf("调用 fun5 之前 p = %p\n", p);
    fun5(p);
    printf("调用 fun5 之后 p = %p\n", p);

    //综上，c语言只有按值调用，没有引用调用。传递地址时，只传递了地址的拷贝。
}