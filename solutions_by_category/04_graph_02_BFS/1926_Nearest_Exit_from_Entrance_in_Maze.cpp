/*
[Medium] 
1926. Nearest Exit from Entrance in Maze
https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        using pii = pair<int, int>;
        // queue<vector<int>> q{{entrance}};
        queue<pii> q;
        q.push({entrance[0], entrance[1]});

        maze[entrance[0]][entrance[1]] = '+';
        int steps = 0;
        // vector<int> dirs = {-1, 0, 1, 0, -1};
        int dirs[5] = {-1, 0, 1, 0, -1};

        while (!q.empty()) {
            ++steps;
            for (int i = q.size(); i > 0; --i) { // OR ~i OR i
                auto [a, b] = q.front(); // Structured binding
                // auto p = q.front();
                // int a = p[0], b = p[1];
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int x = a + dirs[k];
                    int y = b + dirs[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.') {
                        // Retrun we reach the edge
                        if (x == 0 || x == m - 1 || y == 0 || y == n - 1) {
                            return steps;
                        }
                        q.push({x, y});
                        maze[x][y] = '+';
                    }
                }
            }
        }
        return -1;
    }
};