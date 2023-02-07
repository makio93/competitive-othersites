// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), id = 0;
        int res = 0;
        while (id < n) {
            int ri = id, li = id;
            while (ri+1<n && s[id]==s[ri+1]) ++ri;
            res += (ri-id+1) * (ri-id) / 2 + (ri-id+1);
            id = ri + 1;
            while (li-1>=0 && ri+1<n && s[li-1]==s[ri+1]) {
                ++res;
                --li, ++ri;
            }
        }
        return res;
    }
};
