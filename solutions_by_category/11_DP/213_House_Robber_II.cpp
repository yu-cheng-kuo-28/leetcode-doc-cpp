/*
[Medium]
213. House Robber II
https://leetcode.com/problems/house-robber-ii/description/
*/

#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }

    int robLinear(const vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0;
        for (int i = start; i <= end; ++i) {
            int cur = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
