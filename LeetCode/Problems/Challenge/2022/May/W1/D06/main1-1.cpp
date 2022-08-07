// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length(), id = 0;
        vector<int> cnts(n);
        for (int i=0; i<n; ++i) {
            s[id] = s[i];
            if (id-1>=0 && s[id-1]==s[id]) {
                cnts[id] = cnts[id-1] + 1;
                if (cnts[id] == k) id -= k;
            }
            else cnts[id] = 1;
            ++id;
        }
        return s.substr(0, id);
    }
};
