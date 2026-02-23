/*
[Medium]
261. Graph Valid Tree
https://leetcode.com/problems/graph-valid-tree/description/
*/

//! DFS or disjoint set!

// Sol 01: DFS
// O(m + n) | O(m + n) [adjacency list O(m) {n vectors. Total of 2m integers (undirected graph)} | visited vector O(n) | recursion stack O(n)]
// O(n) | O(n)

#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // m = n - 1 | m: edges, n: nodes
        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        // auto dfs = [&](auto&& self, int node) -> void {
        function<void(int)> dfs = [&](int node) {
            visited[node] = true;

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor);
                }
            }
        };

        dfs(0);

        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }

        return true;
    }
};

/* Sol 02: Disjoint Set! 
// O(n * log (n)) | O(n)
class Solution {
public:
    // vector<int> p; // parent 

    bool validTree(int n, vector<vector<int>>& edges) {
        p.resize(n); // cf. reserve()!
        iota(p.begin(), p.end(), 0);

        for (auto e : edges) {
            int a = e[0];
            int b = e[1];
            if (find(a) == find(b)) {
                return false;
            }
            p[find(a)] = find(b); // Note this!!
            --n;
        }
        return n == 1;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p; // parent 
};
*/

// index: 0 1 2 3 4
//  p[x]: 0 1 2 3 4     
//  p[x]: 1 1 2 3 4     
//  p[x]: 1 2 2 3 4  
//  p[x]: 1 2 2 3 4  
