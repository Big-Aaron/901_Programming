//
// 编程实现将一个带头结点的整数链表分成一个奇数链表和一个偶数链表。
// 要求:
// (1)利用原链表中的结点空间作为这二个链表的结点空间，表头节点可以开辟新的空间;
// (2)结点的数据域只有一个整数域;
// (3)单链表的建立写一函数 create() 实现;
// (4)构造奇数和偶数链表的过程写一函数 sub() 实现;
// (5)输出结果写一函数 output() 实现;
// (6)主函数调用这三个函数完成程序功能。
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int num;
    struct Node *next;
} Node, *pNode;

int main(void) {
    pNode create();
    void sub();
    void output();

    int len;
    pNode nums;
    pNode odd = (Node *) malloc(sizeof(Node));
    pNode even = (Node *) malloc(sizeof(Node));
    printf("请输入单链表的长度:\t");
    scanf("%d", &len);
    nums = create(len);
    printf("原链表为:\t");
    output(nums);

    sub(nums, odd, even);
    printf("奇数链表为:\t");
    output(odd);
    printf("偶数链表为:\t");
    output(even);
}

pNode create(int N) {
    pNode p;
    pNode Head = (Node *) malloc(sizeof(Node));
    Head->next = NULL;
    p = Head;
    int temp;
    for (int i = 0; i < N; ++i) {
        pNode node = (Node *) malloc(sizeof(Node));
        node->next = NULL;
        printf("请输入第%2d个节点的数字:\t", i + 1);
        scanf("%d", &(node->num));
        p->next = node;
        p = node;
    }
    return Head;
}

void sub(pNode nums, pNode odd, pNode even) {
    pNode p, q, r;
    r = nums->next, p = odd, q = even;
    while (r) {
        if (r->num % 2 == 0) {
            q->next = r;
            q = r;
            r = r->next;
        } else {
            p->next = r;
            p = r;
            r = r->next;
        }
    }
    p->next = NULL, q->next = NULL;

}

void output(pNode Head) {
    pNode p = Head->next;
    while (p) {
        printf("%d\t", p->num);
        p = p->next;
    }
    printf("\n");
}