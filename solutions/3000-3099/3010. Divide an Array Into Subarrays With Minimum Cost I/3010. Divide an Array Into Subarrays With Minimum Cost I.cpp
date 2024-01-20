class Solution {
public:
    int minimumCost(vector<int>& nums) {
        
        unordered_map<int, int> m;
        int nums_size = nums.size();
        
        for (int i = 0; i < nums_size; ++i) {
            m[nums[i]]++;
        }
            
        int k = nums[0];
        sort(nums.begin(), nums.end());

        if (k == nums[0] || k == nums[1]) {
            k = nums[2];
        }

        return k + nums[0] + nums[1];
    }
};
