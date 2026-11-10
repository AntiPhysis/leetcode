#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        preSum[0] = 0;
        // 计算 nums 的前缀和
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        // 根据前缀和判断左半边数组和右半边数组的元素和是否相同
        for (int i = 1; i < preSum.size(); i++) {
            // 计算 nums[i-1] 左侧和右侧的元素和
            int leftSum = preSum[i - 1] - preSum[0];
            int rightSum = preSum[n] - preSum[i];
            if (leftSum == rightSum) {
                // 相对 nums 数组，preSum 数组有一位索引偏移
                return i - 1;
            }
        }
        return -1;
    }
};
