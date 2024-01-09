//
// Created by Administrator on 2024/1/9.
//

//239. 滑动窗口最大值

// 有难度
// 思路：递减队列

#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> deq;
        for(int i=0;i<nums.size();i++){
            while(deq.size() && nums[i]>deq.back()){
                deq.pop_back();
            }
            deq.push_back(nums[i]);
            if(i>=k-1){
                res.push_back(deq.front());
                if(deq.front() == nums[i-k+1])  // 出队逻辑不好想
                    deq.pop_front();
            }
        }
        return res;
    }
};