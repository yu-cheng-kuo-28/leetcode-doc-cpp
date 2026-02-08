/*
[Medium]
198. House Robber
https://leetcode.com/problems/house-robber/description/
*/

#include <vector>
using namespace std;

class Solution {
public: 
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev2 = 0, prev1 = 0;
        for (int i = 0; i < n; ++i) {
            int cur = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = cur;
        }
        // return cur;
        return prev1; // Edge case: only 1 element | cf. reverse linked list
    }
};