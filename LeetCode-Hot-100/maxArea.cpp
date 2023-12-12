//
// Created by Administrator on 2023/11/25.
//

//11. 盛最多水的容器
// 解题思路：暴力枚举（超时），
// 技巧：双指针（一遍解决）
#include <vector>

#define MIN(a, b)  (a<b ? a:b)
#define MAX(a, b)  (a>b ? a:b)

int maxArea_1(vector<int>& height) {

}

int min(int a, int b){
    return a<b?a:b;
}

// 暴力枚举: 超时
int maxArea(int* height, int heightSize) {
    int max = 0;
    for(int i=0;i<heightSize-1;i++){
        for(int j=i+1;j<heightSize;j++)
        {
            int area = min(height[j], height[i]) * (j-i);
            if(area>max)
                max = area;
        }
    }
    return max;
}

// 双指针
int maxArea(int* height, int heightSize) {
    int max = 0, area=0;
    int left = 0 , right = heightSize-1;
    while(left < right){
        area = MIN(height[left],height[right]) * (right-left);
        if(area>max){
            max = area;
        }
        if(height[left]<height[right]){
            left++;
        } else{
            right--;
        }
    }
    return max;
}