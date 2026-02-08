/*
[Easy]
3827. Count Monobit Integers
https://leetcode.com/problems/count-monobit-integers/description/
*/

class Solution {
public:
    int countMonobit(int n) {
        int cnt = 1; // For 0x 0000 0000

        int i = 1; 
        int x = 1;
        // left to right vs. right to left
        while (x <= n) {
            ++cnt; // For 0x 0000 0001
            x += (1 << i);
            ++i;
        }

        return cnt;
    }
};