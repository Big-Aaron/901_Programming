//
// 某单位的运营成本由 C1 和 C2 两部分组成，它们可以用参数 p 的函数来表示：
// C1=30-8*p C2=10+p^2
// 参数的范围为 0 ~ 10。请确定当运营成本最小时的 p 值（精度为 0.1）
//

#include <stdio.h>
#include <math.h>
#include <float.h>

#define precision 0.1
#define range 10

int main(void) {
    double cMin = DBL_MAX;
    double cTemp = DBL_MAX;
    double pMin = 0;
    double pTemp = 0.1;
    for (int i = 0; i < range / precision; ++i) {
        double C1 = 30 - 8 * pTemp;
        double C2 = 10 + pow(pTemp, 2);
        cTemp = C1 + C2;
        if (cTemp < cMin) {
            cMin = cTemp;
            pMin = pTemp;
        }
        pTemp += 0.1;
    }
    printf("最小运营成本为:%.2lf\t此时的参数 p 为:%.1lf\n", cMin, pMin);
}
