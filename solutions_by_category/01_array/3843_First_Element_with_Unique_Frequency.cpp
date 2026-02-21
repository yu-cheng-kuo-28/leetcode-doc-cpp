/*
[Medium]
3843. First Element with Unique Frequency
https://leetcode.com/problems/first-element-with-unique-frequency/description/
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> freqCount;

        for (int num : nums) {
            if (freqCount[freq[num]] > 0) {
                --freqCount[freq[num]];
            }
            ++freq[num];
            ++freqCount[freq[num]];
        }

        for (int num : nums) {
            if (freqCount[freq[num]] == 1) {
                return num;
            }
        }
        
        return -1;
    }
};