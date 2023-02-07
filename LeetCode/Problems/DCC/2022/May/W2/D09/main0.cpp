// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const vector<string> tar = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        vector<string> res;
        if (n == 0) return res;
        string str;
        auto dfs = [&](auto dfs, int id=0) -> void {
            if (id == n) {
                res.push_back(str);
                return;
            }
            for (char ci : tar[digits[id]-'2']) {
                str.push_back(ci);
                dfs(dfs, id+1);
                str.pop_back();
            }
        };
        dfs(dfs);
        return res;
    }
};
