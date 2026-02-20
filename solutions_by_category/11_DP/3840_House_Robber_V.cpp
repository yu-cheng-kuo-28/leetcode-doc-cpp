/*
[Medium]
3825. Longest Strictly Increasing Subsequence With Non-Zero Bitwise AND
https://leetcode.com/problems/house-robber-v/description/
*/

#include <vector>
using namespace std;

using ll = long long;

class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<ll> f(n + 1, 0); // f[0] = 0
        f[1] = nums[0];

        // f[0] | f[1]   | f[2] | f[3]
        //   0  | nums[0]| 
        for (int i = 2; i <= n; ++i) {
            if (colors[i - 1] != colors[i - 2]) {
                f[i] = max(f[i - 1] + nums[i - 1], f[i - 2] + nums[i - 1]);     
            } else {
                f[i] = max(f[i - 1], f[i - 2] + nums[i - 1]);     
            }
        }
        return f[n];
    }
};