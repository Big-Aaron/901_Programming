//
// 已知用两个单链表分别存储的两个字符串，均按递增次序排列。
// 编程实现将这两个单链表归并为一个按数据域值递减次序排列的单链表。
// 要求:
// ①单链表中每个结点只存放一个字符;
// ②利用原链表中的结点空间存储归并后的单链表，不另外生成新链表;
// ③单链表的建立写一函数(creat)实现;
// ④两个链表归并过程写一函数(sub) 实现;
// ⑤输出结果写一函数(output)实现;
// ⑥主函数调用这三个的数完成程序功能。
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char c;
    struct Node *next;
} Node, *pNode;

int main(void) {
    pNode create();
    pNode sub();
    void output();

    int len;
    pNode str1, str2;
    int temp;

    printf("请输入单链表s1的长度:\t");
    scanf("%d", &len);
    while ((temp = getchar()) != EOF && temp != '\n');
    str1 = create(len);
    output(str1);
    printf("请输入单链表s2的长度:\t");
    scanf("%d", &len);
    while ((temp = getchar()) != EOF && temp != '\n');
    str2 = create(len);
    output(str2);

    str1 = sub(str1, str2);
    output(str1);
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
        printf("请输入第%d个节点的字符:\t", i + 1);
        scanf("%c", &(node->c));
        while ((temp = getchar()) != EOF && temp != '\n');
        p->next = node;
        p = node;
    }
    return Head;
}

pNode sub(pNode S1, pNode S2) {
    // 采取头插法
    pNode Head = (Node *) malloc(sizeof(Node));
    pNode p, q, r, t;
    p = S1->next, q = S2->next, r = NULL, t = NULL;
    while (p && q) {
        if (p->c <= q->c) {
            r = p->next;
            p->next = t;
            t = p;
            p = r;
        } else {
            r = q->next;
            q->next = t;
            t = q;
            q = r;
        }
    }
    if (q == NULL) {
        q = p;
    }
    while (q) {
        r = q->next;
        q->next = t;
        t = q;
        q = r;
    }
    Head->next = t;
    return Head;
}

void output(pNode Head) {
    pNode p = Head->next;
    while (p) {
        printf("%c\t", p->c);
        p = p->next;
    }
    printf("\n");
}