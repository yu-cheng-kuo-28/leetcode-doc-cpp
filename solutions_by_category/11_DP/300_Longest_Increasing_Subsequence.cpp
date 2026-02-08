/*
[Medium] 
300. Longest Increasing Subsequence
https://leetcode.com/problems/longest-increasing-subsequence/description/
*/

#include <vector>
#include <algorithm>
using namespace std;

// O(n log n) | Note the cool logic here to find LIS!
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;

        for (int num : nums) {
            // For a sorted vector, find the position of the smallest element >= num
            auto it = lower_bound(arr.begin(), arr.end(), num);
            if (it == arr.end()) {
                arr.push_back(num);
            } else {
                *it = num;
            }
        }

        return arr.size();
    }
};


/* O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[i], f[j] + 1); // Note the state transition equation
                }
            }
        }

        return *max_element(f.begin(), f.end());
    }
};
*/