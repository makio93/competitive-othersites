// 解説AC4

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> rq, dq;
        for (int i=0; i<n; ++i) (senate[i] == 'R' ? rq : dq).push(i);
        while (!rq.empty() && !dq.empty()) {
            int ri = rq.front(); rq.pop();
            int di = dq.front(); dq.pop();
            if (ri < di) rq.push(ri+n);
            else dq.push(di+n);
        }
        return (!rq.empty()) ? "Radiant" : "Dire";
    }
};
