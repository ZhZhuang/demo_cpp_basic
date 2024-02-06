//
// Created by Administrator on 2024/1/23.
//


#include <stdio.h>
int sum(int a){
    static int b = 3;
    int c= 0;
    c += b++;
    a+=++b;
    return(a + b + c);
}
int main(){
    int i;
    int a = 2;
    for (i=0; i<5; i++){
        printf("%d,",sum(a));
    }

    int b[]= {1,2,3};
    printf("\n%d\n",sizeof(b));
}
