/*
841. Keys and Rooms
https://leetcode.com/problems/keys-and-rooms/
*/

// cf. 207. Course Schedule
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int cnt = 0;
        vector<bool> vis(n, false); // Default: false

        function<void(int)> dfs = [&](int i) {
            if (vis[i]) return;
            vis[i] = true;
            ++cnt;
            for (int j : rooms[i]) {
                dfs(j);
            }
        };

        dfs(0);
        return cnt == n;
    }
};