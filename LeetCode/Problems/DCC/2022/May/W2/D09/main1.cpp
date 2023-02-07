// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const vector<string> tar = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        vector<string> res;
        if (n == 0) return res;
        res.push_back("");
        for (char di : digits) {
            vector<string> nres;
            for (char ti : tar[di-'2']) for (auto str : res) nres.push_back(str+ti);
            swap(nres, res);
        }
        return res;
    }
};
