#include <bits/stdc++.h>
using namespace std;

// 自力WA,4

class Solution {
public:
    string largestMerge(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        map<string, set<pair<int, int>>> memo;
        memo[""].emplace(0, 0);
        for (int i=0; i<n1+n2; ++i) {
            map<string, set<pair<int, int>>> next_memo;
            string orig = memo.rbegin()->first;
            if (i>0 && (int)(memo.rbegin()->second.size())==1) {
                int tid1 = memo.rbegin()->second.begin()->first, tid2 = memo.rbegin()->second.begin()->second;
                if (tid1==n1 || tid2==n2) {
                    if (tid1 == n1) orig += word2.substr(tid2);
                    else if (tid2 == n2) orig += word1.substr(tid1);
                    return orig;
                }
            }
            for (auto p : memo.rbegin()->second) {
                if (p.first < n1) {
                    if (next_memo.empty() || next_memo.rbegin()->first<=orig+word1[p.first]) {
                        next_memo[orig+word1[p.first]].emplace(p.first+1, p.second);
                    }
                }
                if (p.second < n2) {
                    if (next_memo.empty() || next_memo.rbegin()->first<=orig+word2[p.second])
                    next_memo[orig+word2[p.second]].emplace(p.first, p.second+1);
                }
            }
            swap(memo, next_memo);
        }
        return memo.rbegin()->first;
    }
};
