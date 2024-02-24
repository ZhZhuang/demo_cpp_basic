//
// Created by Administrator on 2024/2/22.
//

#include <stdio.h>

union Data {
    int i;
    char x[2];
} a;

int main() {
    a.x[0] = 10;
    a.x[1] = 1;
    printf("%d", a.i);
    return 0;
}