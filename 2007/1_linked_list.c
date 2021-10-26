//
// 若和s2是两个单链表存储的字符串，编程实现:找出串s1中第一个在串s2中出现的字符。若存在这样的字符将其从串s1中删除。
// 要求:
// (1)单个字符串链表的建立过程，写一函数(create)实现，数据从键盘输入;
// (2)查找及删除过程写一函数(search)实现;
// (3)主函数调用create函数和search函数分别实现字符串链表的建立及查找功能，并在主函数中输出s1串的最后结果。
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char c;
    struct Node *next;
} Node, *pNode;

int main(void) {
    pNode create();
    void search();
    void output();
    int len;
    pNode s1, s2;
    int temp;
    printf("请输入单链表s1的长度:\t");
    scanf("%d", &len);
    while ((temp = getchar()) != EOF && temp != '\n');
    s1 = create(len);
    output(s1);
    printf("请输入单链表s2的长度:\t");
    scanf("%d", &len);
    while ((temp = getchar()) != EOF && temp != '\n');
    s2 = create(len);
    output(s2);
    search(s1, s2);
    output(s1);
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


void search(pNode s1, pNode s2) {
    pNode p, q, r;
    q = s2->next;
    while (q) {
        r = s1;
        p = s1->next;
        while (p) {
            if (p->c == q->c) {
                // 删除p所指节点
                r->next=p->next;
                free(p);
                return;
            } else {
                r = r->next;
                p = p->next;
            }
        }
        q = q->next;
    }
    printf("未在s2中找到s1中的字符\n");
}

void output(pNode Head) {
    pNode p = Head->next;
    while (p) {
        printf("%c\t", p->c);
        p = p->next;
    }
    printf("\n");
}