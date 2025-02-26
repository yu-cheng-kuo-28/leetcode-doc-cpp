class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;
        mp[0] = -1; // Note this line

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