/*
300. Longest Increasing Subsequence
https://leetcode.com/problems/longest-increasing-subsequence/description/
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1);
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }

        return *max_element(f.begin(), f.end());
    }
};

/*
Though process:

1. Definitely not greedy, not hash map, so probably be DP
2. DP: Time complexity = O(n^2)
3. Follow-up question (TBD): 2-D LIS. How to find the longest sequence of some points on a 2-D plane with the conditions:
    3-1 x-axis: a_1[0] < a_2[0] < ... < a_n[0]
    3-2 y-axis: a_1[1] > a_2[1] > ... > a_n[1]

As for the O(n * log(n)) solution using BIT (Binary Indexed Tree), it's too hard to code for me at this point:
https://github.com/doocs/leetcode/blob/main/solution/0300-0399/0300.Longest%20Increasing%20Subsequence/README.md
*/