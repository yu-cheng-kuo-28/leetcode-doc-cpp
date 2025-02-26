/*
1730. Shortest Path to Get Food
https://leetcode.com/problems/shortest-path-to-get-food/
*/
class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        using pii = pair<int, int>;
        int dirs[5] = {-1, 0, 1, 0, -1};
        queue<pii> q;

        for (int i = 0, found = 0; i < m, found == 0; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '*') {
                    q.push({i, j});
                    grid[i][j] = 'X';
                    found = 1;
                    break;
                }
            }
        }

        int length = 0;
        while (!q.empty()) {
            ++length;
            for (int i = q.size(); i; --i) { // cf. i / ~i
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

/*
This is one of the most fundamental forms of BFS, 
finding the shortest distance from the start point to the end point.t
*/