/*
[Easy]
190. Reverse Bits
https://leetcode.com/problems/reverse-bits/description/
*/

#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversedInt = 0;
        for (int i = 0; i < 32; ++i) {
            uint32_t bit = (n & 1) << (31 - i);
            reversedInt |= bit;
            n >>= 1;
        }
        return reversedInt;
    }
};