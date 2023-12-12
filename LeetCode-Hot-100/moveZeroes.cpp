//
// Created by Administrator on 2023/11/24.
//

// 283. 移动零
// 这一题在 【同花顺】 的面试题做过
// 技巧：双指针
// 有难度

#include <vector>

// c++ 风格
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = 0;   //  双指针
    while(r < n){
        if(nums[r] != 0){
            swap(nums[l], nums[r]); //  此时 l == r || nums[l] == 0
            l++;                    //  存在 0 的情况下, 势必会出现快慢指针，从而把所有 0 都置换到结尾
        }
        r++;
    }
}



// 好理解一点
void moveZeroes_2(int* nums, int numsSize){
    int slow = 0;
    for(int fast = 0; fast < numsSize; fast++){
        if(nums[fast] != 0)
            nums[slow++] = nums[fast];
    }
    for(slow; slow < numsSize; slow++)
        nums[slow] = 0;
}

//作者：海吞鱼泪
//        链接：https://leetcode.cn/problems/move-zeroes/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// c 风格：更厉害一点!!!
void moveZeroes(int* nums, int numsSize) {
    int slow = 0;
    for(int i=0;i<numsSize;i++){
        int temp = nums[i];
        nums[i]=0;
        if(temp !=0 ){
            nums[slow++] = temp;
        }
    }
}
