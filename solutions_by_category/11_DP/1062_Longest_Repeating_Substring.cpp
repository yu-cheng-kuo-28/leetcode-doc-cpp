/*
[Medium] 1062. Longest Repeating Substring
https://leetcode.com/problems/longest-repeating-substring/
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.length();
        // int f[n][n]; // Faster. But may cause stackoverflow. Use vector instead
        // memset(f, 0, sizeof(f));
        
        vector<vector<int>> f(n, vector<int>(n, 0));
        //  vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));

        int maxLenRepSubstring = 0;

        // Note the i, j relationship!
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (s[i] == s[j]) {
                    f[i][j] = 1 + (j > 0 ? f[i - 1][j - 1] : 0);
                    maxLenRepSubstring = max(maxLenRepSubstring, f[i][j]);
                }
            }
        }

        return maxLenRepSubstring;
    }
};