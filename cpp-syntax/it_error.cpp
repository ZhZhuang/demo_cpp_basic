
// 迭代器发生错误的场景

#include<iostream>
#include<vector>

using namespace std;

int main() {

    vector<int> q{ 1,2,3,4,5,6 };
    // 在这里想把大于2的元素都删除
    for (auto it = q.begin(); it != q.end(); it++) {
        if (*it > 2)
            q.erase(it); // 这里就会发生迭代器失效
    }
    cout <<"-----------------"<<endl;
    // 打印结果
    for (auto it = q.begin(); it != q.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
