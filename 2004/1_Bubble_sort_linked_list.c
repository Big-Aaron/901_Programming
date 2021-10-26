//
// 编程序实现单链表的冒泡排序
// 要求:
// (1)节点的数据域只有一个整数域
// (2)N个节点的整数链表的建立过程，写一函数(create)实现，数据从键盘输入
//

// swap时只交换了节点的整数值，如果要交换节点则swap函数的参数和复杂度陡升

#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y) do{if(&(x)==&(y))break;(x)=(x)+(y);(y)=(x)-(y);(x)=(x)-(y);}while(0);
typedef struct Node {
    int num;
    struct Node *next;
} Node, *pNode;

int main(void) {
    pNode create();
    void bubbleSort();
    void output();
    int N;
    pNode Head;
    printf("请输入一共有多少节点:\t");
    scanf("%d", &N);
    Head = create(N);
    bubbleSort(Head->next, N);
    output(Head);
}

pNode create(int N) {
    pNode p;
    pNode Head = (Node *) malloc(sizeof(Node));
    Head->next = NULL;
    p = Head;
    for (int i = 0; i < N; ++i) {
        pNode node = (Node *) malloc(sizeof(Node));
        node->next = NULL;
        printf("请输入第%d个节点的整数:\t", i + 1);
        scanf("%d", &(node->num));
        p->next = node;
        p = node;
    }
    return Head;
}

void bubbleSort(pNode Head, int N) {
    pNode p, q;
    for (int i = 0; i < N; ++i) {
        p = Head, q = Head->next;
        for (int j = 0; j < N - i - 1; ++j) {
            if (p->num > q->num) {
                SWAP(p->num, q->num);
            }
            p = p->next;
            q = q->next;
        }
    }
}

void output(pNode Head){
    pNode p=Head->next;
    while(p){
        printf("%d\t",p->num);
        p=p->next;
    }
}