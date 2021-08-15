#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        vector<int> tcnt(52);
        for (char c : t) {
            if (isupper(c)) tcnt[c-'A']++;
            else tcnt[c-'a'+26]++;
        }
        int sok = 0, r = 0;
        for (int i=0; i<52; ++i) if (tcnt[i] == 0) ++sok;
        vector<int> scnt(52);
        pair<int, pair<int, int>> mval = { m+5, { m+5, m+5 } };
        for (int l=0; l<m; ++l) {
            while (r<m && sok<52) {
                if (isupper(s[r])) {
                    scnt[s[r]-'A']++;
                    if (scnt[s[r]-'A'] == tcnt[s[r]-'A']) ++sok;
                }
                else {
                    scnt[s[r]-'a'+26]++;
                    if (scnt[s[r]-'a'+26] == tcnt[s[r]-'a'+26]) ++sok;
                }
                ++r;
            }
            if (sok < 52) break;
            mval = min(mval, { r-l, { l, r } });
            if (isupper(s[l])) {
                if (scnt[s[l]-'A'] == tcnt[s[l]-'A']) --sok;
                scnt[s[l]-'A']--;
            }
            else {
                if (scnt[s[l]-'a'+26] == tcnt[s[l]-'a'+26]) --sok;
                scnt[s[l]-'a'+26]--;
            }
        }
        if (mval.first == m+5) return string("");
        else return s.substr(mval.second.first, mval.first);
    }
};
