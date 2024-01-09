//
// Created by Administrator on 2024/1/9.
//

// 题目一：
//一个不重复的数组，[3,4,1,2,5,6]，从中选取n个数，返回所有组合。

// 题目二：
//77. 组合
//给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combine(vector<int> &nums, int len){
        backtracking(nums,0,len);
        return res;
    }

    void backtracking(vector<int> &nums, int startindex, int len){
        if(path.size() >= len){
            res.push_back(path);
            return;
        }
        for(int i = startindex;i<nums.size();i++){
            path.push_back(nums[i]);
            backtracking(nums,i+1,len);
            path.pop_back();
        }
    }

    void print(){
        for(int i=0;i<res.size();i++){
            for(auto j : res[i]){
                cout<< j<<" ";
            }
            cout<<endl;
        }
    }
};


class Solution_2 {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        backtracking(n,1,k);
        return res;
    }

    void backtracking(int n, int startindex, int k){
        if(path.size()>=k){
            res.push_back(path);
            return;
        }
        for(int i= startindex;i<=n;i++){
            path.push_back(i);
            backtracking(n,i+1,k);
            path.pop_back();
        }
    }
};

int main(){
    Solution s;
    vector<int> nums ={1,2,3,4,5,6};
    int len = 3;
    s.combine(nums,len);
    s.print();
}