
//20. 有效的括号

// 大神的写法更简洁

#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

// 简洁
class Solution_official {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }

        unordered_map<char, char> pairs = {
                {')', '('},
                {']', '['},
                {'}', '{'}
        };
        stack<char> stk;
        for (char ch: s) {
            if (pairs.count(ch)) {  // 右括号
                if (stk.empty() || stk.top() != pairs[ch]) {
                    return false;
                }
                stk.pop();
            }
            else {      // 左括号
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};

//作者：力扣官方题解
//        链接：https://leetcode.cn/problems/valid-parentheses/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.empty())
            return true;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            //if(s[i] == '(' || s[i]=='{' || s[i] == '[')
            if(!st.empty() && s[i] == ')' && st.top() == '(')
                st.pop();
            else if(!st.empty() && s[i] == ']' && st.top() == '[')
                st.pop();
            else if(!st.empty() && s[i] == '}' && st.top()  == '{')
                st.pop();
            else
                st.push(s[i]);
        }
        if(!st.empty())
            return false;
        else
            return true;
    }
};

class Solution_1 {
public:
    bool isValid(string s) {
        unordered_map<char,int> m{{'(',1},{'[',2},{'{',3},
                                  {')',4},{']',5},{'}',6}};
        stack<char> st;
        bool istrue=true;
        for(char c:s){
            int flag=m[c];
            if(flag>=1&&flag<=3) st.push(c);
            else if(!st.empty()&&m[st.top()]==flag-3) st.pop();
            else {istrue=false;break;}
        }
        if(!st.empty()) istrue=false;
        return istrue;
    }
};

//作者：腐烂的橘子
//        链接：https://leetcode.cn/problems/valid-parentheses/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

