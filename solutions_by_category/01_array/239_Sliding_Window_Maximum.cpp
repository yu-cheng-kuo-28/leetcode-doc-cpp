/*
[Hard]
239. Sliding Window Maximum
https://leetcode.com/problems/sliding-window-maximum/description/
*/

#include <vector>
#include <queue>
using namespace std;

using pii = pair<int, int>;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pii> q; // max heap by default

        for (int i = 0; i < k - 1; ++i) { 
            q.push({nums[i], -i}); //! Note the logic here! Push the first (k - 1) elements
        }

        vector<int> maxSlidingWindow;
        for (int j = k - 1; j < n; ++j) {
            q.push({nums[j], -j});
            while (-q.top().second <= j - k) { // Restore the index
                q.pop();
            }
            maxSlidingWindow.emplace_back(q.top().first);
        }
        return maxSlidingWindow;
    }
};