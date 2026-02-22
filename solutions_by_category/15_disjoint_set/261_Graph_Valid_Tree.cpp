/*
[Medium]
261. Graph Valid Tree
https://leetcode.com/problems/graph-valid-tree/description/
*/

#include <vector>
#include <numeric> // For iota()!
using namespace std;

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