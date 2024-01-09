//
// Created by Administrator on 2023/12/27.
//

//22. 括号生成

/**
 * 思路一：直接生成，再判断是否合法, 不可取
 * 没有想到判断左右括号的数量
 */

#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string path;
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        backtracking(0, 0, n);
        return result;
    }

    void backtracking(int l, int r, int n){
        // 剪枝
        if(l<r){    // 不剪枝 12ms，剪枝后 4ms
            return;
        }
        if(path.size() >= 2*n){
            //if(valid(path))
            if(l==r)    // 不用 valid 直接 0 ms ！！！
                result.push_back(path);
            return;
        }
        //for(int i=0;i<2;i++){
        //    if(i==0){
                path.push_back('(');
                backtracking(l+1,r,n);
                path.pop_back();
            //}
            //if(i==1){
                path.push_back(')');
                backtracking(l,r+1,n);
                path.pop_back();
        //    }
        //}
    }

    // 不需要了
    bool valid(const string & str) {
        int balance = 0;
        for (char c : str) {
            if (c == '(') {
                ++balance;
            } else {
                --balance;
            }
            if (balance < 0) {
                return false;
            }
        }
        return balance == 0;
    }
};


class Solution_bl {
    bool valid(const string & str) {
        int balance = 0;
        for (char c : str) {
            if (c == '(') {
                ++balance;
            } else {
                --balance;
            }
            if (balance < 0) {
                return false;
            }
        }
        return balance == 0;
    }

    void generate_all(string& current, int n, vector<string>& result) {
        if (n == current.size()) {
            if (valid(current)) {
                result.push_back(current);
            }
            return;
        }
        current += '(';
        generate_all(current, n, result);
        current.pop_back();
        current += ')';
        generate_all(current, n, result);
        current.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        generate_all(current, n * 2, result);
        return result;
    }
};

//作者：力扣官方题解
//        链接：https://leetcode.cn/problems/generate-parentheses/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。