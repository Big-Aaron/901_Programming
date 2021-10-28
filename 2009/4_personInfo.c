//
// 编写函数 R_Info 读入 10 名职工的编号(整型)、姓名(字符串)、联系电话(字符串)放在结构体数组 personInfo 中;
// 编写函数 W_Info1 输出 10 名职工的记录;
// 编写函数 W_Info2 将 10 名职工的记录保存到文件;
// 在主函数中分别调用上述三个函数，实现程序的功能。

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20
typedef struct personInfo {
    int num;
    char name[MaxSize];
    char pNum[12];
} personInfo;

int main() {
    void R_Info();
    void W_Info1();
    void W_Info2();
    personInfo personsInfo[2];
    R_Info(personsInfo, 2);
    W_Info1(personsInfo, 2);
    W_Info2(personsInfo, 2);
}

void R_Info(personInfo *personsInfo, int len) {
    int c;
    for (int i = 0; i < len; ++i) {
        printf("请输入第%d名员工的信息:\n", i + 1);
        printf("编号为:\t");
        scanf("%d", &(personsInfo[i].num));
        while ((c = getchar()) != EOF && c != '\n');
        printf("姓名为:\t");
        fgets(personsInfo[i].name, MaxSize, stdin);
        printf("联系电话为:\t");
        fgets(personsInfo[i].pNum, MaxSize, stdin);
    }
}

void W_Info1(personInfo *personsInfo, int len) {
    for (int i = 0; i < len; ++i) {
        printf("第%d名员工的信息:\n", i + 1);
        printf("编号为:\t%d\n", personsInfo[i].num);
        printf("姓名为:\t%s", personsInfo[i].name);
        printf("联系电话为:\t%s", personsInfo[i].pNum);
    }
}

void W_Info2(personInfo *personsInfo, int len) {
    FILE *fp;
    if ((fp = fopen("./personsInfo.dat", "w")) == NULL) {
        printf("can not open file");
        exit(1);
    }
    fwrite(personsInfo, sizeof(personInfo), len, fp);
    fclose(fp);
}