#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
    const vector<string> tar = { "++X", "X++", "--X", "X--" };
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size(), res = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<4; ++j) if (tar[j] == operations[i]) {
                if (j/2 == 0) ++res;
                else --res;
                break;
            }
        }
        return res;
    }
};
