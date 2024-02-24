//
// Created by Administrator on 2024/2/22.
//
#include <iostream>
using namespace std;

int main(){
    int a[9]={1,2,3,4,5,6,7,8,9};
    int const * const p = a;

    //a++;
    (*a)++;
    //p++;
    //(*p)++;
    cout << a[0]<<endl;
}