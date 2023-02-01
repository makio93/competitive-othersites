// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n = words.size(), res = 0;
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
            int bi = 0, bj = 0;
            for (const char& ci : words[i]) bi |= 1<<(ci-'a');
            for (const char& ci : words[j]) bj |= 1<<(ci-'a');
            if (bi == bj) ++res;
        }
        return res;
    }
};
