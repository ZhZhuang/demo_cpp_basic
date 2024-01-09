//
// Created by Administrator on 2023/12/31.
//

//189. 轮转数组

// 看似简单，实则细节有不少
// 后面是一个标准方法，和考研时数据结构书中的一样

#include <vector>
using namespace std;

class Solution_my {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if(k==0)
            return;
        vector<int> temp(k);
        for(int i=0;i<k;i++){
            temp[i] = nums[nums.size()-k +i ];
        }
        for(int i=nums.size()-1;i>=k;i--){
            nums[i] = nums[i-k];
        }
        for(int i=0;i<k;i++){
            nums[i] = temp[i];
        }
    }
};


class Solution_1 {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};

//作者：御三五 🥇
//链接：https://leetcode.cn/problems/rotate-array/solutions/683855/shu-zu-fan-zhuan-xuan-zhuan-shu-zu-by-de-5937/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。