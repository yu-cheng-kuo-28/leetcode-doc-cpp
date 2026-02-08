/*
[Medium] 
1020. Number of Enclaves
https://leetcode.com/problems/number-of-enclaves
*/

#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};
        
        function<void(int, int)> dfs = [&](int a, int b) {
            if (a < 0 || a >= m || b < 0 || b >= n || grid[a][b] != 1) {
                return;
            }
            grid[a][b] = 0;
            for (int k = 0; k < 4; ++k) {
                int x = a + dirs[k];
                int y = b + dirs[k + 1];
                dfs(x, y);
            }
        };
        
        for (int i = 0; i < m; ++i) {
            dfs(i, 0);
            dfs(i, n - 1);
        }

        for (int j = 1; j < n - 1; ++j) {
            dfs(0, j);
            dfs(m - 1, j);
        }

        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};

/*
Do BFS on the boundry
*/