//
// Created by Administrator on 2023/12/30.
//

// 最优解： 摩尔投票法【现在不用】

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> num_map;
        for(int i : nums){
            num_map[i]++;
        }
        int max=0;
        int res = -1;
        for(auto pair : num_map){
            if(pair.second > max){
                res = pair.first;
                max = pair.second;
            }
        }
        return res;
    }
};