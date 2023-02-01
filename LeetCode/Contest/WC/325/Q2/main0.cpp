// 本番AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
const string CTAR = "abc";
class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        int n = s.length();
        vector<int> mcnt(3), ccnt(3);
        for (int i=0; i<3; ++i) {
            mcnt[i] = count(s.begin(), s.end(), CTAR[i]);
            if (mcnt[i] < k) return -1;
        }
        int res = INF, ri = 0;
        for (int i=0; i<n; ++i) {
            while (ri < n) {
                if (ccnt[s[ri]-'a']+1 > mcnt[s[ri]-'a']-k) break;
                ccnt[s[ri]-'a']++;
                ++ri;
            }
            res = min(res, (n-ri)+i);
            if (ri > i) ccnt[s[i]-'a']--;
            else ri = i + 1;
        }
        return res;
    }
};
