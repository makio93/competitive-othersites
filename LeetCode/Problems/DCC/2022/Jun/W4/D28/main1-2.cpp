// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> ccnt(26);
        for (char& ci : s) ccnt[ci-'a']++;
        priority_queue<int> pq;
        for (int i=0; i<26; ++i) if (ccnt[i] > 0) pq.push(ccnt[i]);
        int res = 0;
        while ((int)(pq.size()) > 1) {
            int vi = pq.top(); pq.pop();
            if (vi == pq.top()) {
                --vi;
                ++res;
                if (vi > 0) pq.push(vi);
            }
        }
        return res;
    }
};
