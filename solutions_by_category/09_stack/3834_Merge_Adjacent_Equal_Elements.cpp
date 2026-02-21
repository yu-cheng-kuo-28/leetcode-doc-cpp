/*
[Medium]
3834. Merge Adjacent Equal Elements
https://leetcode.com/problems/merge-adjacent-equal-elements/description/
*/

#include <vector>
using namespace std;

using ll = long long;

class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        bool isEqual = true;
        vector<ll> stk;
        stk.reserve(nums.size());

        for (int num : nums) {
            ll cur = num;
            while (!stk.empty() && cur == stk.back()) {
                stk.pop_back();
                cur *= 2;
            }
            stk.push_back(cur);
        }

        return stk;
    }
};