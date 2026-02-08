/*
[Medium]
525. Contiguous Array
https://leetcode.com/problems/contiguous-array/description/
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;
        mp[0] = -1; // Deal with edge cases

        for (int i = 0; i < nums.size(); ++i) {
            sum += (nums[i] == 0 ? -1 : 1);
            if (!mp.count(sum)) {
                mp[sum] = i;
                continue;
            }
            ans = max(ans, i - mp[sum]);
        }
        return ans;
    }
};