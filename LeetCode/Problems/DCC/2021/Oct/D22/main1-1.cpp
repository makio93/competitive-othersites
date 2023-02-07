#include <bits/stdc++.h>
using namespace std;

// 解説AC1,Time:O(N)

class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> ccnt;
        for (char ci : s) ccnt[ci]++;
        vector<string> slst(n+1);
        for (auto pi : ccnt) slst[pi.second].append(pi.second, pi.first);
        string res;
        for (int i=n; i>=0; --i) if (!slst[i].empty()) res.append(slst[i]);
        return res;
    }
};
