/*
[Medium] 3824. Minimum K to Reduce Array Within Limit
https://leetcode.com/problems/minimum-k-to-reduce-array-within-limit/
*/

#include <vector>
using namespace std;

using ll = long long;

class Solution {
public:
    int minimumK(vector<int>& nums) {
        int l = 1;
        int r = INT_MAX;
        int validK = -1;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (isValidK(nums, mid)) {
                validK = mid;
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return validK;
    }

    bool isValidK (vector<int>& nums, int k) {
        int n = nums.size();
        ll cnt = 0;
        for (int& num : nums) {
            cnt += (num % k) ? (num / k + 1)  : ((num / k)); 
        }
        return cnt <= ((ll)k * k);
    }
};