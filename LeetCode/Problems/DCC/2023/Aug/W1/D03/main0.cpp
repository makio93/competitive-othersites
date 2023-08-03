// 自力AC

#include <bits/stdc++.h>
using namespace std;

vector<string> tar = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        res.push_back("");
        for (const char& ci : digits) {
            vector<string> tmp;
            for (const string& si : res) for (const char& ti : tar[ci-'2']) tmp.push_back(si+ti);
            swap(tmp, res);
        }
        return res;
    }
};
