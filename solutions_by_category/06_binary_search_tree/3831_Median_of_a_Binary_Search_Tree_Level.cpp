/*
[Medium]
3831. Median of a Binary Search Tree Level
https://leetcode.com/problems/median-of-a-binary-search-tree-level/description/
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

//! STL: nth_element
// BST + BFS

#include <queue>
using namespace std;

class Solution {
public:
    int levelMedian(TreeNode* root, int level) {
        if (!root) {
            return -1;
        }
        queue<TreeNode*> q{{root}};
        // q.push(root);
        int curLevel = 0;

        while (!q.empty()) {
            vector<int> levelValues;
            for (int i = q.size(); i > 0; --i) {
                TreeNode* node = q.front();
                q.pop();
                levelValues.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                } 
                if (node->right) {
                    q.push(node->right);
                }
            }
            if (curLevel == level) {
                int mid = levelValues.size() / 2;
                nth_element(levelValues.begin(),
                            levelValues.begin() + mid,
                            levelValues.end());
                return levelValues[mid];
            }
            ++curLevel;
        }

        return -1;
    }
};