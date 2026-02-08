/*
[Medium]
39. Combination Sum
https://leetcode.com/problems/combination-sum/description/
*/

#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// sum == 0 -> sum < candidates[i] -> dfs (w. push_back() / pop_back())
// dfs 
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        vector<vector<int>> allCombinations;
        vector<int> combination;

        function<void(int, int)> dfs = [&](int i, int sum) {
            if (sum == 0) {
                allCombinations.push_back(combination);
                return;
            }
            if (sum < candidates[i]) {
                return;
            }
            for (int j = i; j < n; ++j) {
                combination.push_back(candidates[j]);
                dfs(j, sum - candidates[j]);
                combination.pop_back();
            }
        };
        dfs(0, target);
        return allCombinations;
    }
};
