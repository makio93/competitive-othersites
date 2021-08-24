#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> stones = { a, b, c };
        sort(stones.rbegin(), stones.rend());
        int score = 0;
        while (1) {
            int sub = min(stones[0]-stones[2], stones[1]);
            if (sub == 0) sub = 1;
            stones[0] -= sub;
            stones[1] -= sub;
            score += sub;
            sort(stones.rbegin(), stones.rend());
            int volid = 0;
            for (int i=0; i<3; ++i) if (stones[i] > 0) ++volid;
            if (volid < 2) break;
        }
        return score;
    }
};
