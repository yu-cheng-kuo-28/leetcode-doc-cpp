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

/*
class Solution {
public: 
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1, 0); // f[0] = 0
        f[1] = nums[0];

        for (int i = 2; i <= n; ++i) {
            f[i] = max(f[i - 1], f[i - 2] + nums[i - 1]);             
        }
        return f[n];
    }
};
*/