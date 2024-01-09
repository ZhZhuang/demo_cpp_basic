//
// Created by Administrator on 2024/1/1.
//

//238. 除自身以外数组的乘积（清晰图解）
// [神奇]，不能使用除法，而且数据中有零

// 技巧：前缀和，前缀乘积
// 技巧满满！！

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();

        // L 和 R 分别表示左右两侧的乘积列表
        vector<int> L(length, 0), R(length, 0);

        vector<int> answer(length);

        // L[i] 为索引 i 左侧所有元素的乘积
        // 对于索引为 '0' 的元素，因为左侧没有元素，所以 L[0] = 1
        L[0] = 1;
        for (int i = 1; i < length; i++) {
            L[i] = nums[i - 1] * L[i - 1];
        }

        // R[i] 为索引 i 右侧所有元素的乘积
        // 对于索引为 'length-1' 的元素，因为右侧没有元素，所以 R[length-1] = 1
        R[length - 1] = 1;
        for (int i = length - 2; i >= 0; i--) {
            R[i] = nums[i + 1] * R[i + 1];
        }

        // 对于索引 i，除 nums[i] 之外其余各元素的乘积就是左侧所有元素的乘积乘以右侧所有元素的乘积
        for (int i = 0; i < length; i++) {
            answer[i] = L[i] * R[i];
        }

        return answer;
    }
};

//作者：力扣官方题解
//        链接：https://leetcode.cn/problems/product-of-array-except-self/solutions/272369/chu-zi-shen-yi-wai-shu-zu-de-cheng-ji-by-leetcode-/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main() {
    // 示例输入（包含0）
    vector<int> nums = {1, 2, 0, 4};
    //vector<int> nums = {-1,1,0,-3,3};

    Solution s;

    // 计算结果
    vector<int> result = s.productExceptSelf(nums);

    // 输出结果
    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
