//
// GDP 通常由投资，净出口，消武，政府购灭组成。现有两个二进制文件分别
// 保存了某国家 2015 及 2016 年每个月的投资，净出口，消费，政府购买数据。
// 保存文件的数据结构为：
// struct GDPInfo {
//     char chMonth[8];//例如：00201501
//     double dInvest;// 投资
//     double detEX;// 净出口
//     double dConsum;// 消费
//     double dGper; // 政府购买
// }
// 请完成该国家 2015年 2016年 的 GDP 对比计算（不考虑平減物价指数）。
// 请编程实现如下的功能:
// 1)打开二进制文件，正确读取其中的各种数据;
// 2)计算每一年的 GDP 数值;
// 3)计算2015年，2016年GDP 中4个组成部分的变化率;
// 4）将2),3）两步求出的数据，保存到文本文件中。
//
#include <stdio.h>
#include <stdlib.h>

#define pwd2015 "./2015.dat"
#define pwd2016 "./2016.dat"
#define pwd "./GPD.dat"

//#define test

typedef struct GDPInfo {
    char chMonth[8];
    double dInvest;
    double detEX;
    double dConsum;
    double dGper;
} GDPInfo;
#ifdef test

void create_db() {
    FILE *fp2015, *fp2016;
    if ((fp2015 = fopen(pwd2015, "wb")) == NULL) {
        fprintf(stderr, "can not open file %s\n", pwd2015);
        exit(EXIT_FAILURE);
    }
    if ((fp2016 = fopen(pwd2016, "wb")) == NULL) {
        fprintf(stderr, "can not open file %s\n", pwd2016);
        exit(EXIT_FAILURE);
    }
    GDPInfo gdpInfos_2015[12];
    GDPInfo gdpInfos_2016[12];
    for (int i = 0; i < 12; ++i) {
        gdpInfos_2015[i].chMonth[0] = (char) (i + '0');
        gdpInfos_2015[i].dInvest = i;
        gdpInfos_2015[i].detEX = i;
        gdpInfos_2015[i].dConsum = i;
        gdpInfos_2015[i].dGper = i;
    }
    for (int i = 0; i < 12; ++i) {
        gdpInfos_2016[i].chMonth[0] = (char) (i + '0');
        gdpInfos_2016[i].dInvest = i * i + 1;
        gdpInfos_2016[i].detEX = i * i + 1;
        gdpInfos_2016[i].dConsum = i * i + 1;
        gdpInfos_2016[i].dGper = i * i + 1;
    }
    fwrite(gdpInfos_2015, 12, sizeof(GDPInfo), fp2015);
    fwrite(gdpInfos_2016, 12, sizeof(GDPInfo), fp2016);

    fclose(fp2015), fclose(fp2016);
}

#endif

int main(void) {
#ifdef test
    create_db();
#endif
    FILE *fp2015, *fp2016, *fout;
    if ((fp2015 = fopen(pwd2015, "rb")) == NULL) {
        fprintf(stderr, "can not open file %s\n", pwd2015);
        exit(EXIT_FAILURE);
    }
    if ((fp2016 = fopen(pwd2016, "rb")) == NULL) {
        fprintf(stderr, "can not open file %s\n", pwd2016);
        exit(EXIT_FAILURE);
    }
    if ((fout = fopen(pwd, "w")) == NULL) {
        fprintf(stderr, "can not open file %s\n", pwd);
        exit(EXIT_FAILURE);
    }
    GDPInfo gdpInfos_2015[12];
    GDPInfo gdpInfos_2016[12];

    fread(gdpInfos_2015, 12, sizeof(GDPInfo), fp2015);
    fread(gdpInfos_2016, 12, sizeof(GDPInfo), fp2016);

    double GDP_2015 = 0;
    double GDP_2015_dInvest = 0;
    double GDP_2015_detEX = 0;
    double GDP_2015_dConsum = 0;
    double GDP_2015_dGper = 0;

    double GDP_2016 = 0;
    double GDP_2016_dInvest = 0;
    double GDP_2016_detEX = 0;
    double GDP_2016_dConsum = 0;
    double GDP_2016_dGper = 0;

    for (int i = 0; i < 12; ++i) {
        GDP_2015_dInvest += gdpInfos_2015[i].dInvest;
        GDP_2015_detEX += gdpInfos_2015[i].detEX;
        GDP_2015_dConsum += gdpInfos_2015[i].dConsum;
        GDP_2015_dGper += gdpInfos_2015[i].dGper;
    }
    GDP_2015 += GDP_2015_dInvest + GDP_2015_detEX + GDP_2015_dConsum + GDP_2015_dGper;
    for (int i = 0; i < 12; ++i) {
        GDP_2016_dInvest += gdpInfos_2016[i].dInvest;
        GDP_2016_detEX += gdpInfos_2016[i].detEX;
        GDP_2016_dConsum += gdpInfos_2016[i].dConsum;
        GDP_2016_dGper += gdpInfos_2016[i].dGper;
    }
    GDP_2016 += GDP_2016_dInvest + GDP_2016_detEX + GDP_2016_dConsum + GDP_2016_dGper;

    double dInvest_rate = GDP_2016_dInvest / GDP_2015_dInvest;
    double detEX_rate = GDP_2016_detEX / GDP_2016_detEX;
    double dConsum_rate = GDP_2016_dConsum / GDP_2016_dConsum;
    double dGper_rate = GDP_2016_dGper / GDP_2016_dGper;

    fprintf(fout, "2015年GDP为:%lf\t2016年GDP为:%lf\n", GDP_2015, GDP_2016);
    fprintf(fout, "2016年投资较2015年变化率为:%lf%%\n", dInvest_rate * 100);
    fprintf(fout, "2016年净出口较2015年变化率为:%lf%%\n", detEX_rate * 100);
    fprintf(fout, "2016年消费较2015年变化率为:%lf%%\n", dConsum_rate * 100);
    fprintf(fout, "2016年政府购买较2015年变化率为:%lf%%\n", dGper_rate * 100);

    fclose(fp2015), fclose(fp2016), fclose(fout);
}