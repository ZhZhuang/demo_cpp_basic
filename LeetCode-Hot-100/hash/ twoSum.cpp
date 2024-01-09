//
// Created by Administrator on 2023/12/27.
//

//1. 两数之和
//只会存在一个有效答案
/**
 * 方法一：暴力，两层for循环
 * 方法二：哈希表
 */

#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;


// 逻辑有问题
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        unordered_map<int ,int> num_map;
        for(int i=0;i<nums.size();i++){
            num_map[nums[i]] = i;
        }

        // 不要遍历hash表
        //for(auto pair : num_map){
        //    // 存在 相加为target的数
        //    if(a.count(target-nums[i])>0&&(a[target-nums[i]]!=i))
        //    if(num_map.find(target - pair.first) != num_map.end() && num_map[target-]){
        //        res[0]=pair.second;
        //        res[1]=num_map[target-pair.first];
        //        return res;
        //    }
        //}

        for(int i=0;i<nums.size();i++){
            int t = target-nums[i];
            if(num_map.count(t)>0 && num_map[t]!=i){
                res[0] = i;
                res[1] = num_map[t];
                return res;
            }
        }
        return res;
    }
};

class Solution_1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

//作者：力扣官方题解
//        链接：https://leetcode.cn/problems/two-sum/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。