class Solution {
public:
    // const static inline vector<int> dirs = {-1, 0, 1, 0, -1};
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        using pii = pair<int, int>;
        int dirs[5] = {-1, 0, 1, 0, -1};
        queue<pii> q;

        for (int i = 0, x = 1; i < m, x == 1; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '*') {
                    q.push({i, j});
                    grid[i][j] = 'X';
                    x = 0;
                    break;
                }
            }
        }

        int length = 0;
        while (!q.empty()) {
            ++length;
            for (int i = q.size(); i; --i) {
                auto [a, b] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int x = a + dirs[k];
                    int y = b + dirs[k + 1];
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;
                    if (grid[x][y] == '#') return length;
                    if (grid[x][y] == 'O') {
                        q.push({x, y});
                        grid[x][y] = 'X';
                    }
                }
            }
        }

        return -1;
    }
};