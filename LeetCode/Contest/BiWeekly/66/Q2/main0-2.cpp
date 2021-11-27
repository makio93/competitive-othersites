#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBuckets(string street) {
        int n = street.length();
        vector<pair<char, int>> runs;
        runs.emplace_back(street[0], 1);
        for (int i=1; i<n; ++i) {
            if (street[i] == runs.back().first) runs.back().second++;
            else runs.emplace_back(street[i], 1);
        }
        int m = runs.size();
        for (int i=0; i<m; ++i) if (runs[i].first=='H' && runs[i].second>=3) return -1;
        if ((runs[0].first=='H'&&runs[0].second>=2) || (runs[m-1].first=='H'&&runs[m-1].second>=2)) return -1;
        if (m==1) {
            if (runs[0].first == 'H') return -1;
            else return 0;
        }
        vector<int> buk(m);
        for (int i=0; i<m; ++i) if (runs[i].first=='H' && runs[i].second>1) {
            if (runs[i-1].second!=1 || buk[i-1]==0) buk[i-1]++;
            buk[i+1]++;
        }
        for (int i=0; i<m; ++i) if (runs[i].first=='H' && runs[i].second==1) {
            if ((i-1>=0&&runs[i-1].second==1&&buk[i-1]==1)||(i+1<m&&runs[i+1].second==1&&buk[i+1]==1)) continue;
            if (i-1>0 && runs[i-1].second==1) buk[i-1]++;
            else if (i+1<m-1 && runs[i+1].second==1) buk[i+1]++;
            else if (i+1<m) buk[i+1]++;
            else buk[i-1]++;
        }
        int res = 0;
        for (int i=0; i<m; ++i) res += buk[i];
        return res;
    }
};
