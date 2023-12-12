
//155. 最小栈

// 分析：做过一次，但是还是想不起来

#include <climits>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> min_st;
    MinStack() {
        min_st.push(INT_MAX);
    }

    void push(int val) {
        if(val<min_st.top()){
            min_st.push(val);
        } else{
            min_st.push(min_st.top());
        }
        st.push(val);
    }

    void pop() {
        if(!st.empty()){
            st.pop();
            min_st.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */