/*
[Medium]
3634. Minimum Removals to Balance Array
https://leetcode.com/problems/minimum-removals-to-balance-array/description/
*/

// Time complexity = O(nlogn) + O(n) = O(nlogn)
using ll = long long;

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }
        sort(nums.begin(), nums.end());

        int maxLen = 1;
        int j = 0;

        for (int i = 0; i < n; ++i) {
            if (j < i) {
                j = i;
            }
            ll limit = 1LL * nums[i] * k;
            while (j < n && 1LL * nums[j] <= limit) {
                ++j;
            }

            maxLen = max(maxLen, j - i);
        }

        return n - maxLen;
    }
};

/*
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        // ranges::sort(nums);

        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            int j = n;
            if (1LL * nums[i] * k <= nums[n - 1]) {
                j = upper_bound(nums.begin(), nums.end(), 1LL * nums[i] * k) - nums.begin(); // nums[i] * k < nums[j]
            }
            maxLen = max(maxLen, j - i);
        }
        return n - maxLen;
    }
};
*/