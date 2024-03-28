class Solution {
public:
    int minimumCost(vector<int>& nums) {

        int k = nums[0];
        sort(nums.begin(), nums.end());

        if (k == nums[0] || k == nums[1]) {
            k = nums[2];
        }

        return k + nums[0] + nums[1];
    }
};