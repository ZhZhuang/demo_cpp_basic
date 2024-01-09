//
// Created by Administrator on 2023/12/27.
//

// 128. 最长连续序列
// 妙！！！
// 盲区：通过迭代器进行初始化
// 字节跳动面试题

#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;    // 记录最长连续序列的长度

        //unordered_set<int> num_set;
        //for (const int& num : nums) {
        //    num_set.insert(num);
        //}

        // 初始化方式
        unordered_set<int> num_set(nums.begin(), nums.end());   // 记录nums中的所有数值
        for(auto num : num_set){
            cout<< num<<" ";
        }
        cout<<endl;

        int seqLen;
        for(int num: num_set){
            // 如果当前的数是一个连续序列的起点，统计这个连续序列的长度
            if(!num_set.count(num - 1)){    // 妙！！！
                seqLen = 1;     // 连续序列的长度，初始为1
                while(num_set.count(++num))seqLen++;    // 不断查找连续序列，直到num的下一个数不存在于数组中
                cout<<"seqlen is: "<<seqLen<<endl;
                res = max(res, seqLen);     // 更新最长连续序列长度
            }
        }
        return res;
    }
};

//作者：画图小匠
//        链接：https://leetcode.cn/problems/longest-consecutive-sequence/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


int main(){
    vector<int> nums = {100,4,200,1,3,2};
    Solution s;
    cout<< "result is: "<< s.longestConsecutive(nums)<<endl;
    return 0;
}