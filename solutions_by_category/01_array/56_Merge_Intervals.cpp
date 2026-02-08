/*
[Medium]
56. Merge Intervals
https://leetcode.com/problems/merge-intervals/description/
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        //     return a[0] < b[0];
        // });
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> mergedIntervals;
        int n = intervals.size();
        int st = intervals[0][0];
        int ed = intervals[0][1];

        for (int i = 1; i < n; ++i) {
            if (ed < intervals[i][0]) {
                mergedIntervals.push_back({st, ed}); // push_back the (i - 1)th element
                st = intervals[i][0];
                ed = intervals[i][1];
            } else {
                // st remains. Extend ed.
                ed = max(ed, intervals[i][1]);
            }
        }

        mergedIntervals.push_back({st, ed}); //! Note this: Push back the last element
        return mergedIntervals;
    }
};