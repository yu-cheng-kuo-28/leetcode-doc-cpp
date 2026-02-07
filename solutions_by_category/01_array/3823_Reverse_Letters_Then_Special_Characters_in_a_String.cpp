/*
[Easy] 3823. Reverse Letters Then Special Characters in a String
https://leetcode.com/problems/reverse-letters-then-special-characters-in-a-string/description/
*/

// #include <cstring>
#include <string>
using namespace std;

class Solution {
public:
    string reverseByType(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            while (!islower(s[i]) && i < j) {
                ++i;
            }
            while (!islower(s[j]) && i < j) {
                --j;
            }
            swap(s[i], s[j]);
            ++i;
            --j;
        }

        i = 0;
        j = n - 1;
        while (i < j) {
            while (islower(s[i]) && i < j) {
                ++i;
            }
            while (islower(s[j]) && i < j) {
                --j;
            }
            swap(s[i], s[j]);
            ++i;
            --j;
        }
        
        return s;
    }
};