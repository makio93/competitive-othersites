#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    int n;
    bool compare_sa(vector<int>& rank, int k, int i, int j) {
        if (rank[i] != rank[j]) return (rank[i] < rank[j]);
        else {
            int ri = (i+k <= n) ? rank[i+k] : -1;
            int rj = (j+k <= n) ? rank[j+k] : -1;
            return (ri < rj);
        }
    }
public:
    string longestDupSubstring(string s) {
        n = s.length();
        if (s == string(n, s.front())) return s.substr(0, n-1);
        vector<int> sa(n+1), rank(n+1);
        for (int i=0; i<=n; ++i) {
            sa[i] = i;
            rank[i] = (i<n) ? s[i] : -1;
        }
        vector<int> tmp(n+1);
        for (int k=1; k<=n; k*=2) {
            sort(sa.begin(), sa.end(), [&](int i, int j) {
                if (rank[i] != rank[j]) return (rank[i] < rank[j]);
                else {
                    int ri = (i+k <= n) ? rank[i+k] : -1;
                    int rj = (j+k <= n) ? rank[j+k] : -1;
                    return (ri < rj);
                }
            });
            tmp[sa[0]] = 0;
            for (int i=1; i<=n; ++i) tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(rank, k, sa[i-1], sa[i]) ? 1 : 0);
            for (int i=0; i<=n; ++i) rank[i] = tmp[i];
        }
        for (int i=0; i<=n; ++i) rank[sa[i]] = i;
        vector<int> lcp(n+1);
        int h = 0;
        lcp[0] = 0;
        pair<int, int> res = { 0, -1 };
        for (int i=0; i<n; ++i) {
            int j = sa[rank[i]-1];
            if (h > 0) --h;
            while (j+h<n && i+h<n) {
                if (s[j+h] != s[i+h]) break;
                ++h;
            }
            lcp[rank[i]-1] = h;
        }
        for (int i=0; i<=n; ++i) res = max(res, { lcp[rank[i]], i });
        return s.substr(res.second, res.first);
    }
};
