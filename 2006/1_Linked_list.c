
//
// 已知用单链表存储的一个字符串，其中含有三种字符(数字字符、字母字符和其他字符),
// 试编写程序构造3个循环的单链表，使得每个表中只含有同一类字符。
// 要求:  (1)利用原链表中的结点空间作为这三个表的结点空间，不另外生成新链表;
//       (2)单链表的建立写一函数(creat);实现构造三个循环链表的过程写一函数(sub)实现;输出结果写一函数(output)实现;
//           主函数调用这三个函数完成程序功能。
//       (3)程序应是非递归的。
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char c;
    struct Node *next;
} Node, *pNode;

int main(void) {
    pNode create();
    void sub();
    void output();
    int len;
    pNode str;
    int temp;
    pNode numStr = (Node *) malloc(sizeof(Node));
    pNode letterStr = (Node *) malloc(sizeof(Node));
    pNode otherStr = (Node *) malloc(sizeof(Node));
    printf("请输入单链表str的长度:\t");
    scanf("%d", &len);
    while ((temp = getchar()) != EOF && temp != '\n');
    str = create(len);
    output(str);
    sub(str, numStr, letterStr, otherStr);
    printf("数字字符链表:\t");
    output(numStr);
    printf("字母字符链表:\t");
    output(letterStr);
    printf("其他字符链表:\t");
    output(otherStr);
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
    p->next = Head;
    return Head;
}

int DistinguishingChar(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    } else if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
        return -1;
    } else {
        return 0;
    }
}

void sub(pNode str, pNode numStr, pNode letterStr, pNode otherStr) {
    pNode p, q, r, l;
    p = numStr;
    q = letterStr;
    r = otherStr;
    l = str->next;
    while (l != str) {
        switch (DistinguishingChar(l->c)) {
            case 1:
                p->next = l;
                p = l;
                l = l->next;
                break;
            case -1:
                q->next = l;
                q = l;
                l = l->next;
                break;
            case 0:
                r->next = l;
                r = l;
                l = l->next;
                break;
            default:
                printf("节点信息处理错误:\n");
                exit(1);
        }
    }
    p->next = numStr;
    q->next = letterStr;
    r->next = otherStr;
}

void output(pNode Head) {
    pNode p = Head->next;
    while (p != Head) {
        printf("%c\t", p->c);
        p = p->next;
    }
    printf("\n");
}