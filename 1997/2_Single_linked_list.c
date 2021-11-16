//
// 有单链表，Head 为链表的头指针，按升序查找并且打印链表中各节点数据，打印完该结点后，把它从链表中游除，直至链表为空。
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
    printf("请输入单链表的长度:\t");
    scanf("%d", &len);
    nums = create(len);
    printf("原链表为:\t");
    output(nums);

    sub(nums);
    output(nums);
}

pNode create(int N) {
    pNode p;
    pNode Head = (Node *) malloc(sizeof(Node));
    Head->next = NULL;
    p = Head;
    for (int i = 0; i < N; ++i) {
        pNode node = (Node *) malloc(sizeof(Node));
        node->next = NULL;
        printf("请输入第 %d 个节点的数字:\t", i + 1);
        scanf("%d", &(node->num));
        p->next = node;
        p = node;
    }
    return Head;
}

void sub(pNode Head) {
    pNode p, q, r;
    while (Head->next) {
        p = Head->next, r = Head, q = Head;// p为遍历工作指针，q指向p的前置节点，r指向当前拥有最小值的节点
        while (p) {
            if (p->num < r->next->num) {
                r = q;
            }
            p = p->next, q = q->next;
        }
        printf("%d\t", r->next->num);
        r->next = r->next->next;
    }
}

void output(pNode Head) {
    pNode p = Head->next;
    while (p) {
        printf("%d\t", p->num);
        p = p->next;
    }
    printf("\n");
}