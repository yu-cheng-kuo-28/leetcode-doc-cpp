/*
[Medium]
1765. Map of Highest Peak
https://leetcode.com/problems/map-of-highest-peak/description
*/

#include <vector>
#include <queue>
using namespace std;

using pii = pair<int, int>;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // isWater[i][j] || 0: land | 1: water
        int m = isWater.size();
        int n = isWater[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};
        queue<pii> q;

        vector<vector<int>> heightMatrix(m, vector<int>(n, -1));
        // vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    heightMatrix[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = a + dirs[k];
                int y = b + dirs[k + 1];
                int currentHeight = heightMatrix[a][b];
                if (x >= 0 && x < m && y >= 0 && y < n && isWater[x][y] == 0 && heightMatrix[x][y] == -1) {
                    q.push({x, y});
                    heightMatrix[x][y] = currentHeight + 1;
                    // visited[x][y] = true;
                }
            }
        }
        return heightMatrix;
    }
};