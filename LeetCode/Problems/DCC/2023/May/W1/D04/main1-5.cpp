// 解説AC5

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<char> que;
        int rcnt = 0, dcnt = 0, rsub = 0, dsub = 0;
        for (int i=0; i<n; ++i) {
            que.push(senate[i]);
            (senate[i] == 'R' ? rcnt : dcnt)++;
        }
        while (rcnt && dcnt) {
            char ci = que.front(); que.pop();
            if (ci == 'R') {
                if (rsub) --rsub;
                else {
                    --dcnt, ++dsub;
                    que.push(ci);
                }
            }
            else {
                if (dsub) --dsub;
                else {
                    --rcnt, ++rsub;
                    que.push(ci);
                }
            }
        }
        return rcnt ? "Radiant" : "Dire";
    }
};
