//
//1、有N个学生，每个学生记录包括学号、姓名、成绩，数据从键盘输入。要求找出成绩最高者的姓名和成绩。
//

#include <stdio.h>

#define MaxSize 20
typedef struct Student {
    int NO;
    char name[MaxSize];
    float score;
} Student;

int main() {
    int N;
    printf("请输入一共有多少学生:\t");
    scanf("%d", &N);
    Student student[N];
    int c;
    float max = 0;
    int imax = 0;
    for (int i = 0; i < N; ++i) {
        printf("请输入第 %d 个学生的学号:\t", i + 1);
        scanf("%d", &student[i].NO);
        while ((c = getchar()) != EOF && c != '\n');
        printf("请输入第 %d 个学生的姓名:\t", i + 1);
        scanf("%s", student[i].name);
        printf("请输入第 %d 个学生的成绩:\t", i + 1);
        scanf("%f", &student[i].score);
        if (student[i].score > max) {
            max = student[i].score;
            imax = i;
        }
    }
    printf("最高分的学生为%s,成绩为%.2f", student[imax].name, student[imax].score);
}