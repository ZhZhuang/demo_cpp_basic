
// 46. 全排列
// 考察：回溯法
// 作者：代码随想录
// https://programmercarl.com/%E5%9B%9E%E6%BA%AF%E7%AE%97%E6%B3%95%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html#%E9%A2%98%E7%9B%AE%E5%88%86%E7%B1%BB
// 在什么地方收获结果？ 叶子中

#include <vector>
using namespace std;


////////////////////
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking (vector<int>& nums, vector<bool>& used) {
        // 此时说明找到了一组
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true)
                continue; // path里已经收录的元素，直接跳过
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};

//作者：代码随想录
//        链接：https://leetcode.cn/problems/permutations/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


// 更难理解一点
class Solution_2 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    void dfs(vector<int> nums, int x) {
        if (x == nums.size() - 1) {
            res.push_back(nums);      // 添加排列方案
            return;
        }
        for (int i = x; i < nums.size(); i++) {
            swap(nums[i], nums[x]);   // 交换，将 nums[i] 固定在第 x 位
            dfs(nums, x + 1);         // 开启固定第 x + 1 位元素
            swap(nums[i], nums[x]);   // 恢复交换
        }
    }
};
//
//作者：Krahets
//        链接：https://leetcode.cn/problems/permutations/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。