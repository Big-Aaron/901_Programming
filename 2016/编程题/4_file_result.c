//
// 在“创新企业” 评选结果的二进制文件中(result.dat）存放100家创新企业的基本信息，这些情况由以下结构体来描述：
// struct Firm
// {
// char FirmName[1001]; //企业的名称
// int FirmScore[10]; //十位评委对企业的创新效果的打分
// 请编程实现如下的功能：
// 1）打开该二进制文件，将数据内容读入到一个结构体数组中。
// 2）根据评委的打分输出总分数第一名的企业名称。
// 3）根据评委的打分输出乎均分数第一名的企业名称。
// 4）输出平均分在 90 分以上以及 80-89 分的企业的个数。
// 注意：在计算平均的过程中需要去掉一个最高分，去掉一个最低分。
//

#include <stdio.h>
#include <stdlib.h>

#define pwd "./result.dat"
#define N 100
#define test
typedef struct Firm {
    char FirmName[1001]; //企业的名称
    int FirmScore[10]; //十位评委对企业的创新效果的打分
} Firm;
#ifdef test

void create_db() {
    FILE *fp;
    if ((fp = fopen(pwd, "wb")) == NULL) {
        fprintf(stderr, "con open file %s", pwd);
        exit(EXIT_FAILURE);
    }
    Firm firms[N];
    for (int i = 0; i < N; ++i) {
        firms[i].FirmName[0] = 'A';
        for (int j = 0; j < 10; ++j) {
            firms[i].FirmScore[j] = (i * 10 + j) % 100;
        }
    }
    fwrite(firms, sizeof(Firm), N, fp);
    fclose(fp);
}

#endif

int main(void) {
#ifdef test
    create_db();
#endif
    FILE *fp;
    if ((fp = fopen(pwd, "rb")) == NULL) {
        fprintf(stderr, "con open file %s", pwd);
        exit(EXIT_FAILURE);
    }
    Firm firms[N];
    fread(firms, sizeof(Firm), N, fp);
    fclose(fp);

    int sumMax = 0; // 总分最高分
    int isumMax = 0; // 总分最高分的下标

    int aveMax = 0; // 平均分最高分
    int iaveMax = 0; // 平均分最高分的下标

    int above_90_num = 0; // 平均分在90分以上的企业个数
    int between_89_90_num = 0; // 平均分在80-89分之间的企业个数

    for (int i = 0; i < N; ++i) {

        int tempsumMax = 0;
        int tempaveMax = 0;

        int tempMax = 0;
        int tempMim = 100;

        // 计算该公司的最高分与最低分
        for (int j = 0; j < 10; ++j) {
            if (firms[i].FirmScore[j] > tempMax) {
                tempMax = firms[i].FirmScore[j];
            }
            if (firms[i].FirmScore[j] < tempMim) {
                tempMim = firms[i].FirmScore[j];
            }
            // 计算最高分
            tempsumMax += firms[i].FirmScore[j];
        }
        // 更新总分最高分
        if (tempsumMax > sumMax) {
            sumMax = tempsumMax;
            isumMax = i;
        }
        // 计算平均分
        tempaveMax = (tempsumMax - tempMax - tempMim) / 8;
        printf("平均分为%d\n", tempaveMax);
        // 更新平均分最高分
        if (tempaveMax > aveMax) {
            aveMax = tempaveMax;
            iaveMax = i;
        }
        // 更新平均分在90分以上的企业个数
        if (tempaveMax >= 90)above_90_num++;
        // 更新平均分在80-89分之间的企业个数
        if (tempaveMax >= 80 && tempaveMax < 90)between_89_90_num++;
    }
    printf("总分第一名是%s,总分为:%d\n", firms[isumMax].FirmName, sumMax);
    printf("平均分第一名是%s,总分为:%d\n", firms[iaveMax].FirmName, aveMax);
    printf("平均分在90分以上的企业个数为:%d\n", above_90_num);
    printf("平均分在80-89分之间的企业个数为:%d\n", between_89_90_num);

}