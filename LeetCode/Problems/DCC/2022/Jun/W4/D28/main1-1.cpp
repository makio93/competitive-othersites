// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> ccnt(26);
        for (char& ci : s) ccnt[ci-'a']++;
        unordered_set<int> st;
        int res = 0;
        for (int i=0; i<26; ++i) {
            while (ccnt[i]>0 && st.find(ccnt[i])!=st.end()) {
                ccnt[i]--;
                ++res;
            }
            if (ccnt[i] > 0) st.insert(ccnt[i]);
        }
        return res;
    }
};
