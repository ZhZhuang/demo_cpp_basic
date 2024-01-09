//
// Created by Administrator on 2024/1/3.
//

//232. 用栈实现队列

#include <stack>
using namespace std;

class MyQueue {
private:
    std::stack<int> A, B;

public:
    MyQueue() {}

    void push(int x) {
        A.push(x);
    }

    int pop() {
        int peek = this->peek();
        B.pop();
        return peek;
    }

    int peek() {
        if (!B.empty()) return B.top();
        if (A.empty()) return -1;
        while (!A.empty()){
            B.push(A.top()), A.pop();
        }
        int res = B.top();
        return res;
    }

    bool empty() {
        return A.empty() && B.empty();
    }
};
//
//作者：Krahets
//        链接：https://leetcode.cn/problems/implement-queue-using-stacks/solutions/2363977/232-yong-zhan-shi-xian-dui-lie-qing-xi-t-pi4l/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。