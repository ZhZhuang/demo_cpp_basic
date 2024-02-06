//
// Created by Administrator on 2024/1/27.
//

#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> numbers = {1, 2, 3, 4, 5};

    vector<int>::iterator p= numbers.begin();
    cout << *p<<endl;

    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        // 使用 auto 推断迭代器类型
        cout << *it << " ";
    }

}


