/*
[Medium]
1905. Count Sub Islands
https://leetcode.com/problems/count-sub-islands/
*/

#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();
        static constexpr int dirs[5] = {-1, 0, 1, 0, -1};
        
        function<bool(int, int)> dfs = [&](int a, int b) {
            // bool isInGrid1 = true;
            int isInGrid1 = grid1[a][b];
            grid2[a][b] = 0;

            for (int k = 0; k < 4; ++k) {
                int x = a + dirs[k];
                int y = b + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid2[x][y]) {
                    isInGrid1 &= dfs(x, y);
                }
            }
            return isInGrid1;
        };

        // bool isInGrid1 = true;
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j]) {
                    cnt += dfs(i, j);
                }
            }
        }

        return cnt;
    }
};