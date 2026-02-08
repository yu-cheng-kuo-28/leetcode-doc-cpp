/*
[Easy]
338. Counting Bits
https://leetcode.com/problems/counting-bits/description/
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        // cf. vector<int> ans(n + 1, 5); | vector<int> ans{5, 6};
        for (int i = 1; i <= n; ++i) {
            ans[i] = ans[i & (i - 1)] + 1; // "i & (i - 1)": Clear the rightmost set bit
            // 12 = 1100
            // 11 = 1011
            // 12 & 11 = 1000 = 8
        }
        return ans;
    }
};
