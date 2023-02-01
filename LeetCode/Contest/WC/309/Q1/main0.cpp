// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int n = s.length();
        for (int i=0; i<26; ++i) {
            char tar = (char)('a'+i);
            int li = -1, ri = -1;
            for (int j=0; j<n; ++j) if (s[j] == tar) {
                if (li == -1) li = j;
                else ri = j;
            }
            if (li!=-1 && ri-li-1!=distance[i]) return false; 
        }
        return true;
    }
};
