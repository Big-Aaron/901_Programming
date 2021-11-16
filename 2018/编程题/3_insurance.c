//
//
// 某保险公司汽车险产品中，共有十辆汽车保单，每张保单包含了如下的信息:汽车发动机号，汽车品牌，首次投保费用，使用年限等。
// 请编程:
// 1)完成当前汽车投保费用的计算。其中:
// 投保费用 = 当前汽车价值 * 6%。
// 当前汽车价值 = 首次投保费用 - 首次投保费用 * 折旧率(10%) * 使用年限。
// 汽车残值 = 5000人民币。(当汽车价值低于残值时，直接按残值算不进行折旧)。
// 2)输出当前保单费用最多的汽车费用
// 说明:汽车信息需要从键盘输入。
//

#include <stdio.h>

#define N 10
#define MaxSize 21
#define salvage 5000
typedef struct Car {
    char engineNumber[MaxSize];
    char name[MaxSize];
    double first_time_fee;
    int years;
    double currentValue;
    double cost;
} Car;

int main(void) {
    Car cars[N];
    int c;
    double costMax = 0;
    for (int i = 0; i < N; ++i) {
        printf("请输入第%d份保险的信息:\n", i + 1);
        printf("汽车发动机号为:\t");
        scanf("%s", cars[i].engineNumber);
        while ((c = getchar()) != EOF && c != '\n');
        printf("汽车品牌为:\t");
        scanf("%s", cars[i].name);
        while ((c = getchar()) != EOF && c != '\n');
        printf("首次投保费用为:\t");
        scanf("%lf", &cars[i].first_time_fee);
        printf("使用年限为:\t");
        scanf("%d", &cars[i].years);

        cars[i].currentValue = cars[i].first_time_fee - cars[i].first_time_fee * 0.1 * cars[i].years;
        if (cars[i].currentValue < salvage) {
            cars[i].currentValue = salvage;
        }
        cars[i].cost = cars[i].currentValue * 0.06;
        if (cars[i].cost > costMax) {
            costMax = cars[i].cost;
        }
    }
    printf("当前保单费用最多的汽车费用为: %lf\t", costMax);
}