#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int n = words1.size(), m = words2.size();
        unordered_map<string, int> cnt1, cnt2;
        for (int i=0; i<n; ++i) cnt1[words1[i]]++;
        for (int i=0; i<m; ++i) cnt2[words2[i]]++;
        int res = 0;
        for (auto pi : cnt1) if (pi.second == 1) {
            if (cnt2.find(pi.first)!=cnt2.end() && cnt2[pi.first]==1) ++res;
        }
        return res;
    }
};
