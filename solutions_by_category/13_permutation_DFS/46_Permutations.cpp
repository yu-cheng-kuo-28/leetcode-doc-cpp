/*
[Medium]
46. Permutations
https://leetcode.com/problems/permutations/
*/

#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> t(n, -1);
        vector<bool> vis(n, false);
        
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.push_back(t);
                return;
            }
            for (int k = 0; k < n; ++k) {
                if (!vis[k]) {
                    vis[k] = true;
                    t[i] = nums[k];
                    dfs(i + 1);
                    vis[k] = false; // backtracking
                }
            }
        };
        dfs(0);
        return ans;
    }
};

/*
Related problems:

841. Keys and Rooms
https://leetcode.com/problems/keys-and-rooms/

39. Combination Sum
https://leetcode.com/problems/combination-sum/
*/