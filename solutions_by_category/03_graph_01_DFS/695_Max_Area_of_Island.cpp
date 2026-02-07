/*
[Medium] 695. Max Area of Island
https://leetcode.com/problems/max-area-of-island/
*/

#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int area_max = 0;
        int area_temp = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};

        function<void(int, int)> dfs = [&](int a, int b) {
            if (a < 0 || a >= m || b < 0 || b >= n || grid[a][b] == 0) {
                return;
            }
            grid[a][b] = 0;
            ++area_temp;
            for (int k = 0; k < 4; ++k) {
                int x = a + dirs[k];
                int y = b + dirs[k + 1];
                dfs(x, y);
            }
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(i, j);
                area_max = max(area_max, area_temp);
                area_temp = 0;
            }
        }

        return area_max;
    }
};
