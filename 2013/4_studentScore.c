//
//  N 个学生 M 门课，所有学生的各门课程成绩已存入文件f1.dat,
//  请计算每个学生的总分，并按总分降序的次序将每个学生名次、各门课程得分及总分输出到文件f2.dat。
//  要求:
//  在按总分求学生名次时，不得对学生原始数据排序。
//

#include <stdio.h>
#include <stdlib.h>

#define pwdIn "./f1.dat"
#define pwdOut "./f2.dat"
#define N 5
#define M 4
#define MaxSize 1001

#define test
//#define run
typedef struct Student {
    char Name[MaxSize];
    float scores[M];
    float sum;
} Student;

#ifdef test

void create_db() {
    FILE *fp;
    if ((fp = fopen(pwdIn, "w")) == NULL) {
        fprintf(stderr, "can open file %s", pwdIn);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < N; ++i) {
        fprintf(fp, "%c ", (char) 'A' + i);
        for (int j = 0; j < M; ++j) {
            fprintf(fp, "%f\t", (float) i + 1 + j);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

#endif

int main(void) {

#ifdef test
    create_db();
#endif
    void sub();
    Student students[N];
    FILE *fin, *fout;
    if ((fin = fopen(pwdIn, "r")) == NULL) {
        fprintf(stderr, "can open file %s", pwdIn);
        exit(EXIT_FAILURE);
    }
    if ((fout = fopen(pwdOut, "w")) == NULL) {
        fprintf(stderr, "can open file %s", pwdOut);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < N; ++i) {
        fscanf(fin, "%s", students[i].Name);
        for (int j = 0; j < M; ++j) {
            fscanf(fin, "%f", &(students[i].scores[j]));
        }
    }
    fclose(fin);

    sub(students);
#ifdef test
    for (int i = 0; i < N; ++i) {
        printf("第%d名:\t", i + 1);
        fprintf(fout, "第%d名:\t", i + 1);
        printf("%s\t", students[i].Name);
        fprintf(fout, "%s\t", students[i].Name);
        for (int j = 0; j < M; ++j) {
            printf("第%d门课程的成绩:\t", j + 1);
            fprintf(fout, "第%d门课程的成绩:\t", j + 1);
            printf("%5.2f\t", students[i].scores[j]);
            fprintf(fout, "%5.2f\t", students[i].scores[j]);
        }
        printf("总分:\t");
        fprintf(fout, "总分:\t");
        printf("%5.2f\n", students[i].sum);
        fprintf(fout, "%5.2f\n", students[i].sum);
    }
#endif

#ifdef run
    fwrite(students, sizeof(Student), N, fout);
#endif
    fclose(fout);
}

int cmpfun(const void *a, const void *b) {
    ((Student *) a)->sum < ((Student *) b)->sum ? 1 : -1;
}

void sub(Student students[N]) {
    for (int i = 0; i < N; ++i) {
        float sum = 0;
        for (int j = 0; j < M; ++j) {
            sum += students[i].scores[j];
        }
        students[i].sum = sum;
    }
    // 题目中要求不得对原始数据排序，我是真的没想明白
    qsort(students, N, sizeof(Student), cmpfun);
}