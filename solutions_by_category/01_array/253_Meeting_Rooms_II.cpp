/*
[Medium]
253. Meeting Rooms II
https://leetcode.com/problems/meeting-rooms-ii/description/
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = 1000010;
        vector<int> overlap(n, 0);

        for (auto& interval : intervals) {
            ++overlap[interval[0]]; // start: ++
            --overlap[interval[1]]; // end: --
        }

        for (int i = 0; i < n - 1; ++i) {
            overlap[i + 1] += overlap[i];
        }
        return *max_element(overlap.begin(), overlap.end()); // Note *max_element()
    }
};
