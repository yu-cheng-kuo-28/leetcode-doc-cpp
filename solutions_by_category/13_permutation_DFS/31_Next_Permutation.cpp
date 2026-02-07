/*
31. Next Permutation
https://leetcode.com/problems/next-permutation/
*/
/*
1 9 4 8 5 4 7 5 4 3 2 1
1 9 4 8 5 4(i) 7 5 4 3 2 1
1 9 4 8 5 4(i) 7 5(j) 4 3 2 1
1 9 4 8 5 5 7 4 4 3 2 1 
1 9 4 8 5 5 1 2 3 4 4 7
*/

#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2; // Start the rightmost element
        while (i >= 0 && nums[i] >= nums[i + 1]) { //
            --i;
        }

        if (~i) { // If i = -1
            for (int j = n - 1; j > i; --j) {
                if (nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

/*
Thought process of why the algorithm give the exactly next lexicographically greater permutation:

1. Find the longest lexicographically non-ascending suffix (which is the lexicographically greatest suffix for that suffix), 
and pinpoint the index i
(Edge case: if i == -1 at this stage, then we will reverse the whole array later on)

2. We need to increase i to get the possibly lexicographically greater array, so we find the 
first number greater than nums[i] at the righthand side of nums[i], that is nums[i + 1] to nums[n - 1]
(Give the example "1 9 4 8 5 4 7 5 4 3 2 1", "1 9 4 8 5 5 1 2 3 4 5 7" is a 
lexicographically greater array by change the number at index = 5 from 4 to 5, 
which give us a concept of how to find the next lexicographically greater)

3. Now we get a lexicographically greater array and increase nums[i] as less as much, 
then let's look at nums[i + 1] to nums[n - 1] to make num[i] to nums[n - 1] lexicographically increase 
as less as possible, so we need to reverse nums[i + 1] to nums[n - 1] (which is still a lexicographically 
non-ascending suffix) to get the lexicographically smallest permutation that is lexicographically greater 
than the original permutation
*/