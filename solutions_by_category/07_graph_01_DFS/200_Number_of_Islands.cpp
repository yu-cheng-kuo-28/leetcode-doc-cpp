/*
[Medium] 
200. Number of Islands
https://leetcode.com/problems/number-of-islands/
*/

#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};

        // dfs 
        function<void(int, int)> dfs = [&](int a, int b) {
            // Check the boundary and valid condition at first (cf. BFS) 
            if (a < 0 || a >= m || b < 0 || b >= n || grid[a][b] == '0') {
                return;
            }
            grid[a][b] = '0';
            for (int k = 0; k < 4; ++k) {
                int x = a + dirs[k];
                int y = b + dirs[k + 1];
                dfs(x, y);
            }
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    dfs(i, j);
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};