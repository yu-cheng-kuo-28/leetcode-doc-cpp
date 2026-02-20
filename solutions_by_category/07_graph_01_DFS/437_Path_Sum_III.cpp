/*
[Medium]
437. Path Sum III
https://leetcode.com/problems/path-sum-iii/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#include <unordered_map>
#include <functional>
using namespace std;

using ll = long long;

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<ll, int> cnt; // (value, count)
        // The variable ans must be inside the lambda function dfs
        cnt[0] = 1; // !Deal with the edge cases! cf. 560. Subarray Sum Equals K

        function<int(TreeNode*, long)> dfs = [&](TreeNode* node, long s) {
            if (!node) {
                return 0;
            }
            s += node->val;
            int curCount = cnt[s - targetSum];
            ++cnt[s];
            
            curCount += dfs(node->left, s) + dfs(node->right, s); // Note this line
            
            --cnt[s]; // Backtracking: remember to minus the cnt!!
            return curCount;
        };
        return dfs(root, 0);
    }
};

