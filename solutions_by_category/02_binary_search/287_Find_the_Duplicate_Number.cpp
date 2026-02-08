/*
[Medium]
287. Find the Duplicate Number
https://leetcode.com/problems/find-the-duplicate-number/description/
*/

#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        // Constant extra space: binary search | linear runtime: unordered_map
        while (l < r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int& num : nums) {
                cnt += (num <= mid);
            }
            if (cnt > mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};