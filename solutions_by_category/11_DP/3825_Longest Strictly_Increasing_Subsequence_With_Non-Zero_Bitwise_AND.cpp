/*
[Medium]
3825. Longest Strictly Increasing Subsequence With Non-Zero Bitwise AND
https://leetcode.com/problems/longest-strictly-increasing-subsequence-with-non-zero-bitwise-and/description/
*/

//! STL: lower_bound/upper_bound

#include <vector>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int cntMax = 0;

        for (int b = 0; b < 31; ++b) {
            vector<int> filtered;
            int mask = 1 << b;

            for (int num : nums) {
                if (num & mask) {
                    filtered.push_back(num);
                }
            }

            if (!filtered.empty()) {
                cntMax = max(cntMax, LIS(filtered));
            }
        }

        return cntMax;
    }

private:
    int LIS(const vector<int>& nums) {
        // O(n log n)
        vector<int> dp;
        for (int num : nums) {
            auto it = lower_bound(dp.begin(), dp.end(), num);
            if (it == dp.end()) {
                dp.push_back(num);
            } else {
                *it = num;
            }
        }
        return dp.size();
    }
};
