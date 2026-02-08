/*
[Medium]
57. Insert Interval
https://leetcode.com/problems/insert-interval/description/
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> insertedIntervals;
        bool isInserted = false;
        int stNew = newInterval[0];
        int edNew = newInterval[1];

        for (auto& interval : intervals) {
            int st = interval[0];
            int ed = interval[1];

            // Case 01: stNew | edNew | st | ed
            // Case 02: stNew | st | edNew | ed
            // Case 03: stNew | st | ed | edNew
            // Case 04: st | stNew | edNew | ed
            // Case 05: st | stNew | ed | edNew
            // Case 06: st | ed | stNew | edNew
            if (edNew < st) { // Case 01
                if (!isInserted) {
                    insertedIntervals.push_back({stNew, edNew});
                    // insertedIntervals.emplace_back(vector<int>{stNew, edNew});
                    isInserted = true;
                }
                insertedIntervals.push_back({st, ed});
            } else if (ed < stNew) { // Case 06
                insertedIntervals.emplace_back(interval);
            } else { // Case 02/03/04/05 (overlapped)
                // ed_new >= st && st_new <= ed
                stNew = min(stNew, st);
                edNew = max(edNew, ed);
                // doesn't push_back() until the end !! You don't know the number of overlapped intervals
            }
        }

        if (!isInserted) {
            insertedIntervals.push_back({stNew, edNew}); // push back until all the overlapped intervals are merged
        }

        return insertedIntervals;
    }
};
