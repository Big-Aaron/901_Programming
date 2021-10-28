//
// 有10个学生5门课，按学生平均分由高到低的顺序输出学生学号、各门课程的成绩以及平均分
// 1. 第一种方法: (15分)
//      ①在主函数中输入学号和成绩，分别用数组存放;
//      ②自定义一个函数计算平均分、排序并输出结果，用数组指针进行处理。
// 2. 第二种方法: (25分)
//      ①在主函数中输入学号和成绩，用结构体数组存放:
//      ②自定义一个函数计算平均分，并将学号、各门课的成绩和平均分存放在磁盘文件stud中，用数组指针进行处理;
//      ③在主函数中读取stud文件中的内容并输出;
//      ④自定义一个函数将stud文件中的学生数据按平均分进行排序，将排好序的学生数据存入stud_sort文件中，用数组指针进行处理:
//      ⑤在主函数中读取stud_sort文件中的内容并输出。
//

#include <stdio.h>
#include <stdlib.h>

#define test1
//#define run1

#define test2
//#define run2

#define Numsize 8
#define pwd_stud "./stud.dat"
#define pwd_stud_sort "./stud_sort.dat"

// 使用fwrite将数据写入文件，需要用fread读出数据，此时文件是二进制形式，人不可读，但其实打开文件时用 wb/b rb/r 都可以，本人默认此时为:二进制文件
//#define write_file_by_fwrite
// 使用fprintf将数据写入文件，需要用fscanf读出数据，此时文件是文本形式，人可读，但其实打开文件时用 wb/b rb/r 都可以，本人默认此时为:文本文件
#define write_file_by_fprintf

typedef struct student {
    char name[Numsize];
    float score[5];
    float ave;
} student;

int main() {
    void Average_score_sort_array();
    void Average_score_struct_write_by_fwrite();
    void Average_score_struct_write_by_fprintf();
    void Average_score_sort_struct();
#ifdef test1
    char *names[10] = {"001", "002", "003", "004", "005", "006", "007", "008", "009", "010"};
    float score1[6] = {1, 2, 3, 4, 5, 0};
    float score2[6] = {2, 3, 4, 5, 6, 0};
    float score3[6] = {3, 4, 5, 6, 7, 0};
    float score4[6] = {4, 5, 6, 7, 8, 0};
    float score5[6] = {5, 6, 7, 8, 9, 0};
    float score6[6] = {6, 7, 8, 9, 10, 0};
    float score7[6] = {7, 8, 9, 10, 11, 0};
    float score8[6] = {8, 9, 10, 11, 12, 0};
    float score9[6] = {9, 10, 11, 12, 13, 0};
    float score10[6] = {10, 11, 12, 13, 14, 0};
    float *scores[10] = {&score1[0], &score2[0], &score3[0], &score4[0], &score5[0], &score6[0], &score7[0], &score8[0],
                         &score9[0], &score10[0]};
    Average_score_sort_array(names, scores);
#endif

#ifdef run1
    char *names[10];
    float *scores[10];
    for (int i = 0; i < 10; ++i) {
        printf("请输入第%d个学生的学号:\t", i + 1);
        char *name = (char *) malloc(sizeof(char) * Numsize);
        scanf("%s", name);
        names[i] = name;
        float *score = (float *) malloc(sizeof(float) * 6);
        if (score != NULL) {
            for (int j = 0; j < 5; ++j) {
                printf("请输入第%d个学生的第%d门课程的成绩:\t", i + 1, j + 1);
                scanf("%f", &score[j]);
            }
            score[5] = 0;
            scores[i] = score;
        } else {
            printf("系统内存以无连续空间保存数据");
            exit(1);
        }
    }
    Average_score_sort_array(names, scores);
#endif

#ifdef test2
    student students[10] = {{"001", 1,  2,  3,  4,  5,  0},
                            {"002", 2,  3,  4,  5,  6,  0},
                            {"003", 3,  4,  5,  6,  7,  0},
                            {"004", 4,  5,  6,  7,  8,  0},
                            {"005", 5,  6,  7,  8,  9,  0},
                            {"006", 6,  7,  8,  9,  10, 0},
                            {"007", 7,  8,  9,  10, 11, 0},
                            {"008", 8,  9,  10, 11, 12, 0},
                            {"009", 9,  10, 11, 12, 13, 0},
                            {"010", 10, 11, 12, 13, 14, 0}};
#endif

#ifdef run2
    student students[10];
    for (int i = 0; i < 10; ++i) {
        printf("请输入第%d个学生的学号:\t", i + 1);
        scanf("%s", students[i].name);
        for (int j = 0; j < 5; ++j) {
            printf("请输入第%d个学生的第%d门课程的成绩:\t", i + 1, j + 1);
            scanf("%f", &(students[i].score[j]));
        }
        students[i].ave = 0;
    }
#endif

#ifdef write_file_by_fwrite
    Average_score_struct_write_by_fwrite(students, pwd_stud);
    FILE *fp;
    int i = 0;
    if ((fp = fopen(pwd_stud, "rb")) == NULL) {
        printf("can not open file %s", pwd_stud);
        exit(1);
    }
    fread(students, sizeof(student), 10, fp);
    for (i = 0; i < 10; ++i) {
        printf("学号:\t%s\t各科成绩:\t", students[i].name);
        for (int j = 0; j < 5; ++j) { printf("%5.2f\t", students[i].score[j]); }
        printf("\t平均分:%5.2f\n", students[i].ave);
    }
    fclose(fp);
    Average_score_sort_struct(students);
    printf("排序后\n");
    if ((fp = fopen(pwd_stud_sort, "rb")) == NULL) {
        printf("can not open file %s", pwd_stud_sort);
        exit(1);
    }
    for (i = 0; i < 10; ++i) {
        fread(students, sizeof(student), 1, fp);
        printf("学号:\t%s\t各科成绩:\t", students[i].name);
        for (int j = 0; j < 5; ++j) { printf("%5.2f\t", students[i].score[j]); }
        printf("\t平均分:%5.2f\n", students[i].ave);
    }
#endif

#ifdef write_file_by_fprintf
    Average_score_struct_write_by_fprintf(students, pwd_stud);

    FILE *fp;
    int i = 0;
    if ((fp = fopen(pwd_stud, "r")) == NULL) {
        printf("can not open file %s", pwd_stud);
        exit(1);
    }
    while (!feof(fp)) {
        fscanf(fp, "%s\t", students[i].name);
        printf("学号:\t%s\t各科成绩:\t", students[i].name);
        for (int j = 0; j < 5; ++j) {
            fscanf(fp, "%f", &students[i].score[j]);
            printf("%2.2f\t", students[i].score[j]);
        }
        fscanf(fp, "%f\n", &students[i].ave);
        printf("平均分:%2.2f\n", students[i].ave);
        i++;
    }
    fclose(fp);

    Average_score_sort_struct(students);

    printf("排序后\n");
    if ((fp = fopen(pwd_stud_sort, "r")) == NULL) {
        printf("can not open file %s", pwd_stud_sort);
        exit(1);
    }
    i = 0;
    while (!feof(fp)) {
        fscanf(fp, "%s", students[i].name);
        printf("学号:\t%s\t各科成绩:\t", students[i].name);
        for (int j = 0; j < 5; ++j) {
            fscanf(fp, "%f", &students[i].score[j]);
            printf("%2.2f\t", students[i].score[j]);
        }
        fscanf(fp, "%f\n", &students[i].ave);
        printf("平均分:%2.2f\n", students[i].ave);
        i++;
    }
#endif

}

void Average_score_sort_array(char *names[10], float *scores[10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            scores[i][5] += scores[i][j];
        }
        scores[i][5] /= 5;
    }
    float *ftemp = NULL;
    char *Ctemp = NULL;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10 - i - 1; ++j) {
            if (scores[j][5] < scores[j + 1][5]) {
                ftemp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = ftemp;
                Ctemp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = Ctemp;
            }
        }
    }
    printf("排序后的结果为:\n");
    for (int i = 0; i < 10; ++i) {
        printf("学号:%s\t各科目成绩:", names[i]);
        for (int j = 0; j < 5; ++j) {
            printf("%2.2f\t", scores[i][j]);
        }
        printf("平均分:%2.2f\n", scores[i][5]);
    }
}

void Average_score_struct_write_by_fwrite(student students[10], char *pwd) {
    FILE *fp;
    if ((fp = fopen(pwd, "wb")) == NULL) {
        printf("can not open file %s", pwd);
        exit(1);
    }
    for (int i = 0; i < 10; ++i) {
        students[i].ave = 0;
        for (int j = 0; j < 5; ++j) {
            students[i].ave += students[i].score[j];
        }
        students[i].ave /= 5;
    }
    fwrite(students, sizeof(student), 10, fp);
    fclose(fp);
}


void Average_score_struct_write_by_fprintf(student students[10], char *pwd) {
    FILE *fp;
    if ((fp = fopen(pwd, "w")) == NULL) {
        printf("can not open file %s", pwd);
        exit(1);
    }
    for (int i = 0; i < 10; ++i) {
        fprintf(fp, "%s\t", students[i].name);
        students[i].ave = 0;
        for (int j = 0; j < 5; ++j) {
            fprintf(fp, "%2.2f\t", students[i].score[j]);
            students[i].ave += students[i].score[j];
        }
        students[i].ave /= 5;
        fprintf(fp, "%2.2f\n", students[i].ave);
    }
    fclose(fp);
}

int cmpfun(const void *a, const void *b) {
    return (*(student *) a).ave < (*(student *) b).ave ? 1 : -1;
}

void Average_score_sort_struct(student students[10]) {
    qsort(students, 10, sizeof(student), cmpfun);

#ifdef write_file_by_fwrite
    Average_score_struct_write_by_fwrite(students, pwd_stud_sort);
#endif

#ifdef write_file_by_fprintf
    Average_score_struct_write_by_fprintf(students, pwd_stud_sort);
#endif
}
