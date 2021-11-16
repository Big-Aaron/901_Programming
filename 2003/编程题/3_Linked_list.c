//
// 程序实现两个整系数二元多项式的加法，例如，两个多项式的为:
// A(x,y)=5x^6y^3+4x^2y^3+7xy 和 B(x,y)=5x^9y^3+4x^2y^3-7x^2y+10
// 结果为A(x,y)=5x^9y^3+5x^6y^3+8x^2y^3+7xy+10
// 要求：
//  (1）采用链表存储多项式，每一结点含三个域：指数域、系数域、指针域
//  (2）将 B 多项式加到 A 上，结果是A所指的单链表不另外生成新链表（否则不得分)
//  (3）A、B 所指的多项式链表的建立过程，写一函数(input)实现，以系数为0结束输入；
//      相加过程写一函数(add)实现，在主函数中调用这两个函数。不要求输出结果

// 该算法中链表带头结点
// 使用递归进行链表的合并，虽然复杂度比指针遍历合并大，但编写难度低，不易出错
// 为检验结果，写了个output进行输出，但题目没有要求
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int N;
    int Ix;
    int Iy;
    struct Node *next;
} Node, *pNode;

int main() {
    pNode Input();
    pNode add();
    void Output();
    pNode AHead;
    pNode BHead;
    printf("请输入A(x,y)多项式,按x的指数降序排列顺序输入");
    AHead = Input();
    Output(AHead);
    printf("请输入B(x,y)多项式,按x的指数降序排列顺序输入");
    BHead = Input();
    Output(BHead);
    AHead->next = add(AHead->next, BHead->next);
    Output(AHead);
}

pNode Input() {
    int n;
    pNode p;
    pNode Head = (Node *) malloc(sizeof(Node));
    Head->next = NULL;
    p = Head;
    printf("系数为:\t");
    scanf("%d", &n);
    while (n != 0) {
        pNode node = (Node *) malloc(sizeof(Node));
        node->next = NULL;
        node->N = n;
        printf("x的指数为:");
        scanf("%d", &(node->Ix));
        printf("y的指数为:");
        scanf("%d", &(node->Iy));
        p->next = node;
        p = node;
        printf("请继续输入多项式,按x的指数降序排列顺序输入,或输入0结束");
        printf("系数为:");
        scanf("%d", &n);
    }
    return Head;
}

pNode add(Node *AHead, Node *BHead) {// 采用递归
    if (AHead == NULL)return BHead;
    if (BHead == NULL)return AHead;
    if (AHead->Ix < BHead->Ix) {// 结果按x指数升序排列
        BHead->next = add(AHead, BHead->next);
        return BHead;
    }
    if (AHead->Ix > BHead->Ix) {// 结果按x指数升序排列
        AHead->next = add(AHead->next, BHead);
        return AHead;
    }
    if (AHead->Ix == BHead->Ix) {
        if (AHead->Iy == BHead->Iy) {// 合并同类项
            AHead->N = AHead->N + BHead->N;
            AHead->next = add(AHead->next, BHead->next);
            return AHead;
        }
        if (AHead->Iy < BHead->Iy) {// 按y指数的降序排列
            AHead->next = add(AHead->next, BHead);
            return AHead;
        }
        if (AHead->Iy > BHead->Iy) {// 按y指数的降序排列
            BHead->next = add(AHead, BHead->next);
            return BHead;
        }
    }
}

void Output(pNode Head) {
    pNode p = Head->next;
    printf("多项式为:");
    while (p != NULL) {
        printf("%d*(x^%d)*(y^%d)+", p->N, p->Ix, p->Iy);
        p = p->next;
    }
    printf("\b \n");
}