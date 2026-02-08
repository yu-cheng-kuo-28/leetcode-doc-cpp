/*
[Easy]
268. Missing Number
https://leetcode.com/problems/missing-number/
*/

#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int missingNum = n; // Note this: There're (n - 1) numbers in the vector nums!
        for (int i = 0; i < n; ++i) {
            missingNum ^= (i ^ nums[i]);
        }
        return missingNum;
    }
};