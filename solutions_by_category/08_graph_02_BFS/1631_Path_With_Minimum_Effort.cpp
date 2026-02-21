/*
[Medium] 
1631. Path With Minimum Effort
- BFS + Bibary Search
https://leetcode.com/problems/path-with-minimum-effort/
*/
/*
cf. 
[Medium] 
1730. Shortest Path to Get Food
https://leetcode.com/problems/shortest-path-to-get-food/

It's straighforward to ask why can't this problem be solved by the same appraoch of 1730.?
*/

#include <vector>
#include <queue>
using namespace std;

using pii = pair<int, int>;

class Solution {
public:
    bool canReachWithEffort(const vector<vector<int>>& heights, int effort) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // vector<int> directions = {-1, 0, 1, 0, -1, 0};
        int dirs[5] = {-1, 0, 1, 0, -1};

        // BFS 
        queue<pii> q;
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == (m - 1) && y == (n - 1)) {
                return true;
            }

            for (int i = 0; i < 4; ++i) {
                int a = x + dirs[i];
                int b = y + dirs[i + 1];
                if (a >= 0 && a < m && b >= 0 && b < n && !visited[a][b]) {
                    if (abs(heights[x][y] - heights[a][b]) <= effort) {
                        visited[a][b] = true;
                        q.push({a, b});
                    }
                }
            }
        }

        return false;
    }
    
    //! Original only this member function
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();
        int l = 0, r = 0;

        // The maximum adjacent height difference in the grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i < m - 1) {
                    r = max(r, abs(heights[i][j] - heights[i + 1][j]));
                }
                if (j < n - 1) {
                    r = max(r, abs(heights[i][j] - heights[i][j + 1]));
                }
            }
        }

        int result = r;
        
        while (l <= r) {
            int mid = (l + r) >> 1;
            // int mid = l + ((r - l) >> 1);
            if (canReachWithEffort(heights, mid)) {
                result = mid; // So it's (l <= r) instead of (l < r)
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return result;
    }
};

/*
I encountered a similar problem at an OA of a big tech
*/