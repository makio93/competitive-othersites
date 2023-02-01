#include <bits/stdc++.h>
using namespace std;

// 解説AC

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0, pcnt = 0;
        for (string& si : bank) {
            int ncnt = 0;
            for (char ci : si) if (ci == '1') ++ncnt;
            if (ncnt > 0) {
                res += ncnt * pcnt;
                pcnt = ncnt;
            }
        }
        return res;
    }
};
