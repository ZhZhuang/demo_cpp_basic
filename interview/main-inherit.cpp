//
// Created by Zhao Zhuang on 2024/2/3.
//

// 2021年的面试
// 分析代码的输出
#include <stdio.h>
#include <iostream>

class CBase {
public:
    CBase() { std::cout << "1"; }
    ~CBase() { std::cout << "2"; }
};

class CObject : public CBase {
public:
    CObject() { std::cout << "3"; }
    ~CObject() { std::cout << "4"; }
};

CBase function(CObject object) {
    return object;
}

class CBase2 {
public:
    CBase2(){ std::cout <<"1";}
    virtual ~CBase2(){ std::cout <<"2";}
};

class CObject2 :public CBase2 {
public:
    CObject2() { std::cout <<"3"; }
    ~CObject2() {std::cout << "4";}
};

int main() {
    CBase* pBase=new CObject();
    delete pBase;
    printf("\r\n");
    CBase2* pBase2=new CObject2();
    delete pBase2;
    printf("\r\n");
    function(CObject());
    return 0;
}
