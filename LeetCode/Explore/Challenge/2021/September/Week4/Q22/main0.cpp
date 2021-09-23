#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size(), res = 0;
        vector<vector<int>> acnt(n, vector<int>(26));
        for (int i=0; i<n; ++i) for (char ci : arr[i]) acnt[i][ci-'a']++;
        for (int i=0; i<(1<<n); ++i) {
            int len = 0;
            vector<int> ccnt(26);
            for (int j=0; j<n; ++j) if ((i>>j)&1) {
                len += arr[j].length();
                for (int j2=0; j2<26; ++j2) ccnt[j2] += acnt[j][j2];
            }
            bool ok = true;
            for (int j=0; j<26; ++j) if (ccnt[j] > 1) ok = false;
            if (ok) res = max(res, len);
        }
        return res;
    }
};
