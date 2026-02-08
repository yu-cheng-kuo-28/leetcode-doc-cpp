/*
[Medium]
994. Rotting Oranges
https://leetcode.com/problems/rotting-oranges/description/
*/

#include <vector>
#include <queue>
using namespace std;

using pii = pair<int, int>;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0; // count of all the fresh oragnes
        queue<pii> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++cnt;
                } else if (grid[i][j] == 2) {
                    q.emplace(i, j);  // cf. q.push({i, j}); | The rotting oranges
                }
            }
        }

        int minutes = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};

        while (!q.empty() && cnt > 0) {
            ++minutes;
            for (int i = q.size(); i > 0; --i) {
                auto [a, b] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int x = a + dirs[k];
                    int y = b + dirs[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.emplace(x, y);  // cf. q.push({i, j});
                        --cnt;
                    }
                }
            }
        }
        return cnt > 0 ? -1 : minutes;
    }
};
