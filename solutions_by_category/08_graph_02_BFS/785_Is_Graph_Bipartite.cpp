/*
[Medium]
785. Is Graph Bipartite?
https://leetcode.com/problems/is-graph-bipartite/description/
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (color[i] != 0) {
                continue;
            }
            queue<int> q;
            q.push(i);
            color[i] = 1;
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (int neighbor : graph[node]) {
                    if (color[neighbor] == 0) {
                        color[neighbor] = -color[node];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};


/* DFS version | Possible stack overflow & unintuitive
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);

        function<bool(int, int)> dfs = [&](int a, int z) {
            color[a] = z;
            for (int b : graph[a]) {
                if (color[b] == z || (color[b] == 0 && !dfs(b, -z))) { //! Note this condition
                    return false;
                }
            }
            return true;
        };

        for (int i = 0; i < n; ++i) {
            if (color[i] == 0 && !dfs(i, 1)) {
                return false;
            }
        }

        return true;
    }
};
*/