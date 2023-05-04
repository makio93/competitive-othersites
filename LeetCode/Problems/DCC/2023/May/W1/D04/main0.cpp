// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        deque<char> str, stk;
        for (int i=0; i<n; ++i) str.push_back(senate[i]);
        int rcnt = count(senate.begin(), senate.end(), 'R'), ccnt = n - rcnt;
        while (rcnt>0 && ccnt>0) {
            if (stk.empty() || stk.front() == str.front()) stk.push_back(str.front());
            else {
                (str.front() == 'R' ? rcnt : ccnt)--;
                str.push_back(stk.front());
                stk.pop_front();
            }
            str.pop_front();
        }
        return rcnt > 0 ? "Radiant" : "Dire";
    }
};
