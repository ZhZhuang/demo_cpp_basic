//
// Created by Administrator on 2024/2/22.
//


#include <stdio.h>

int main() {
    int n, i;
    printf("请输入要输出的斐波那契数列的项数：");
    scanf("%d", &n);

    // 为数列分配空间
    long long fibonacci[n]; // 使用long long以防止溢出

    // 初始化数列的前两项
    fibonacci[0] = 0;
    if (n > 1) {
        fibonacci[1] = 1;
    }

    // 使用循环计算斐波那契数列的剩余项
    for (i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    // 输出斐波那契数列的前n项
    printf("斐波那契数列的前%d项为：\n", n);
    for (i = 0; i < n; i++) {
        printf("%lld ", fibonacci[i]);
    }
    printf("\n");

    return 0;
}