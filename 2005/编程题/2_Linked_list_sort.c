//
// 设A和B分别是两个有序循环单链表(即表中结点已经按降序排序)，
// pa 和 pb 分别指向这两个循环单链表的尾结点。设计一个程序，将这两个链表归并为一个有序的循环链表。
//
//要求:
// (1)结点的数据域只有一个整数域;
// (2)将B有序表归并到A电，结果是pa指向循环链表的尾结点，不另外生成新链表:
// (3) A、B所表示的有序链表建立过程，写一函数(input)插入实现:归并过程写一函数(merger)实现，在主函数中调用这两个函数。
// (4)程序应是非递归的。
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int num;
    struct Node *next;
} Node, *pNode;

int main(void) {
    pNode input();
    pNode merger();
    void output();
    int len;
    pNode pa, pb;
    printf("请输入有序循环单链表A的长度:\t");
    scanf("%d", &len);
    pa = input(len);
    output(pa->next);
    printf("请输入有序循环单链表B的长度:\t");
    scanf("%d", &len);
    pb = input(len);
    output(pb->next);
    output(merger(pa, pb));
}

pNode input(int N) {
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
    p->next = Head;
    return p;
}

pNode merger(pNode pa, pNode pb) {
    pNode Head = (Node *) malloc(sizeof(Node));
    pNode AHead, BHead;
    AHead = pa->next;
    BHead = pb->next;
    pNode p, q, r;
    p = AHead->next;
    q = BHead->next;
    r = Head;
    if (AHead->next->num >= BHead->next->num) {
        Head->next = AHead->next;
    } else {
        Head->next = BHead->next;
    }
    while (p != AHead || q != BHead) {
        if (p->num < q->num) {
            r->next = q;
            r = q;
            q = q->next;
        } else {
            r->next = p;
            r = p;
            p = p->next;
        }
    }
    if (p == AHead) {
        r->next = q;
        pb->next = Head;
    } else {
        r->next = p;
        pa->next = Head;
    }
    return Head;
}

void output(pNode Head) {
    pNode p = Head->next;
    while (p != Head) {
        printf("%d\t", p->num);
        p = p->next;
    }
    printf("\n");
}