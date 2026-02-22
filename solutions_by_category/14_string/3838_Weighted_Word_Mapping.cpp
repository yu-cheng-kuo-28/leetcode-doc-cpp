/*
[Easy]
3838. Weighted Word Mapping
https://leetcode.com/problems/weighted-word-mapping/description/
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int m = words.size();
        string s;
        s.reserve(m); //! Remember to reserve!

        for (int i = 0; i < m; ++i) {
            int sum = 0;
            for (char word : words[i]) {
                sum += weights[word - 'a'];
            }
            sum %= 26;
            char out = char('z' - sum);
            s.push_back(out);
        }

        return s;
    }
};