//
// Created by Administrator on 2023/12/30.
//

// 75. 颜色分类

#include <vector>
#include <algorithm>    // sort

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return;
    }
};