//
// Created by Administrator on 2024/1/5.
//

#include <vector>
#include <iostream>
using namespace std;
class Solution{
public:
    void quickSort(vector<int> &nums, int l, int r){
        if(l>=r){
            return;
        }
        int temp = nums[l], i=l, j = r;
        while (i<j){
            while (i<j && nums[j]>=temp) j--;
            if(nums[j]<temp)
            {
                swap(nums[i],nums[j]);
                i++;
            }
            while (i<j && nums[i]<=temp) i++;
            if(nums[i]>temp)
            {
                swap(nums[i],nums[j]);
                j--;
            }
        }
        quickSort(nums,l,j-1);
        quickSort(nums,j+1,r);
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,2,1,5,6,4,7,8,9};
    s.quickSort(nums,0,nums.size()-1);
    for(int i:nums){
        cout<< i<<" ";
    }
    return 0;
}