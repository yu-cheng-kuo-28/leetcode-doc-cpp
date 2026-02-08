/*
[Medium]
40. Combination Sum II
https://leetcode.com/problems/combination-sum-ii/
*/

#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        int n = candidates.size();
        vector<vector<int>> allCombinations;
        vector<int> combination;

        function<void(int, int)> dfs = [&](int i, int sum) {
            if (sum == 0) {
                allCombinations.push_back(combination);
                return;
            }
            if (i >= n || sum < candidates[i]) {
                return;
            }
            for (int j = i; j < n; ++j) {
                // Don't forget to check
                if (j > i && candidates[j] == candidates[j - 1]) {
                    continue;
                }
                combination.push_back(candidates[j]);
                dfs(j + 1, sum - candidates[j]);
                combination.pop_back();
            }
        };

        dfs(0, target);
        return allCombinations;
    }
};