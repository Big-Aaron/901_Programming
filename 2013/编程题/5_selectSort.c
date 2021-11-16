//
// 编程实现将给定的一组整数采用选择排序法按由小到大的顺序排序。
// 要求:
// (1)编写函数create()根据已知整数数组构造一个单链表，假设结点只有一个整数数据域。
// (2)编写函数sort()采用选择排序方法对已知链表进行排序。
// (3)在主函数中完成数据的输入与结果的输出。
//
#include <stdio.h>
#include <stdlib.h>


#define SWAP(x, y) do{if(&(x)==&(y))break;(x)=(x)+(y);(y)=(x)-(y);(x)=(x)-(y);}while(0);

typedef struct Node {
    int num;
    struct Node *next;
} Node, *pNode;

int main(void) {
    pNode create();
    void sort();
    void output();

    int len;
    pNode nums;
    printf("请输入单链表的长度:\t");
    scanf("%d", &len);
    nums = create(len);
    printf("原链表为:\t");
    output(nums);

    sort(nums, len);
    printf("排序后链表为:\t");
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
        printf("请输入第%2d个节点的数字:\t", i + 1);
        scanf("%d", &(node->num));
        p->next = node;
        p = node;
    }
    return Head;
}

void sort(pNode nums, int N) {
    pNode p;
    pNode r = nums->next;
    pNode pmin;
    for (int i = 0; i < N; ++i) {
        p = r, pmin = r;
        while (p != NULL) {
            if (p->num < pmin->num) {
                pmin = p;
            }
            p = p->next;
        }
        SWAP(r->num, pmin->num);
        r = r->next;
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