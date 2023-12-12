
//35. 搜索插入位置
//给定一个排序数组和一个目标值，在数组中找到目标值，
// 并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//请必须使用时间复杂度为 O(log n) 的算法。


// 仔细考虑，作对不容易！！

#include <vector>
using namespace std;

class Solution {
public:
    // 边界不对，需要仔细考虑
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        int mid;
        //if(target>nums.back()){
        //    return nums.size();
        //}

        while (low<high){
            mid = (low+high) >> 1;
            if(nums[mid]>target)
                high = mid;
            else if(nums[mid]<target)
                low = mid;
            else
                return mid;
        }
        return mid;
    }
};

// 参考
class Solution_1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=-1,right=nums.size(),mid;

        while(left+1 < right)
        {
            mid=(left+right) >> 1;

            if(nums[mid] < target)
                left=mid;
            else
                right=mid;
        }

        return right;
    }
};


// 参考
class Solution_2 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0,right=n-1;
        int mid=0;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]<target){
                left=mid+1;
            }else if(nums[mid]>target){
                right=mid-1;
            }else{
                return mid;
            }
        }
        return left;
    }
};

//作者：921l
//链接：https://leetcode.cn/problems/search-insert-position/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。