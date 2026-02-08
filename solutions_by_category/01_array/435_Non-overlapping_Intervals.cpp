/*
[Medium]
435. Non-overlapping Intervals
https://leetcode.com/problems/non-overlapping-intervals/description/
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //! Sorting by end time guarantees optimality
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1]; //! sort by intervalEnd instead of IntervalStart
        });

        int removeCount = 0;
        int intervalEnd = intervals[0][1];
        int n = intervals.size();

        for (int i = 1; i < n; ++i) {
            if (intervalEnd <= intervals[i][0]) {
                intervalEnd = intervals[i][1];
            } else {
                ++removeCount;
            }
        }
        return removeCount;
    }
};