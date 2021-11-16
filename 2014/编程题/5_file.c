//
// 设文件student.dat中存放着年级 1000 名学生的基本情况，这些情况由以下结构体来描述:
//
// struct student
// {
// long int num;
// char name[10];
// int age;
// char sex;
// char addr[40];
// };
//
//请编写程序，
// a)在 main 函数中打开 student.dat 文件，并将所有数据按照学号排序后保存在一个student类型的数组中。
// b)编写函数，函数首部为 void print(struct student *s, int m, int n)，打印该数组中从学号为m到学号为n的数据。
// c)编写函数，函数首部为 struct student search(struct student *s, int num)，利用折半查找算法查找学号num的学生，并将该学生的信息打印输出。
// d)编写函数，函数首部为 void write(struct student *s)，将数组写入到backup.dat文件中，
//

#include <stdio.h>
#include <stdlib.h>

//#define test

struct student {
    long int num;
    char name[10];
    int age;
    char sex;
    char addr[40];
};

void print(struct student *s, int m, int n);

struct student search(struct student *s, int num);

void write(struct student *s);

int cmpfun(const void *a, const void *b) {
    return ((struct student *) a)->num > ((struct student *) b)->num ? 1 : -1;
}

#ifdef test

void create_db() {
    FILE *fp;
    if ((fp = fopen("./student.dat", "w")) == NULL) {
        fprintf(stderr, "can not open file %s", "./student.dat");
        exit(EXIT_FAILURE);
    }
    struct student students[1000];
    for (int i = 0; i < 1000; ++i) {
        students[i].num = rand()%1000;
        students[i].name[0] = 'L';
        students[i].name[1] = 'X';
        students[i].age = i % 27;
        students[i].sex = 'F';
        students[i].addr[0] = 'B';
        students[i].addr[1] = 'J';
    }
    fwrite(students, sizeof(struct student), 1000, fp);
    fclose(fp);
}

#endif

int main() {

#ifdef test
    create_db();
#endif

    FILE *fp;
    struct student students[1000];
    if ((fp = fopen("./student.dat", "r")) == NULL) {
        fprintf(stderr, "can not open file %s", "./student.dat");
        exit(EXIT_FAILURE);
    }
    fread(students, sizeof(struct student), 1000, fp);
    fclose(fp);

    qsort(students, 1000, sizeof(struct student), cmpfun);

    print(students, 100, 120);

    search(students, 727);

    write(students);
}

void print(struct student *s, int m, int n) {
    for (int i = 0; i < 1000; ++i) {
        if (s[i].num >= m && s[i].num <= n) {
            printf("%ld %s %d %c %s\n", s[i].num, s[i].name, s[i].age, s[i].sex, s[i].addr);
        }
        if (s[i].num > n)break;
    }
}

struct student search(struct student *s, int num) {
    int left;
    int right;
    int mid;
    left = 0, right = 1000;
    while (left <= right) {
        mid = (left + right) / 2;
        if (s[mid].num == num) {
            printf("找到学号为\t%ld\t%s\t%d\t%c\t%s\n", s[mid].num, s[mid].name, s[mid].age, s[mid].sex, s[mid].addr);
            return s[mid];
        }
        if (s[mid].num > num) {
            right = mid - 1;
        }
        if (s[mid].num < num) {
            left = mid + 1;
        }
    }
    if (right < left)printf("没有找到");
    return *((struct student *)malloc(sizeof (struct student)));
}

void write(struct student *s) {
    FILE *fp;
    if ((fp = fopen("./backup.dat", "w")) == NULL) {
        fprintf(stderr, "can not open file %s", "./backup.dat");
        exit(EXIT_FAILURE);
    }
    fwrite(s, sizeof(struct student), 1000, fp);
    fclose(fp);
}