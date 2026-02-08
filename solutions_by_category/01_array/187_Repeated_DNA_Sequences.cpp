/*
[Medium] 
187. Repeated DNA Sequences
https://leetcode.com/problems/repeated-dna-sequences/
*/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> cnt;
        vector<string> repeatedDNASeq;
        int m = s.size() - 9;

        for (int i = 0; i < m; ++i) {
            auto tenLetterSeq = s.substr(i, 10);
            ++cnt[tenLetterSeq];
            if (cnt[tenLetterSeq] == 2) {
                repeatedDNASeq.emplace_back(tenLetterSeq);
            }
        }

        return repeatedDNASeq;
    }
};