/*
[Easy]
191. Number of 1 Bits
https://leetcode.com/problems/number-of-1-bits/description/
*/

class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while (n) {
            n &= n - 1; // Clear the rightmost set bit
            ++cnt;
        }
        return cnt;
    }
};
