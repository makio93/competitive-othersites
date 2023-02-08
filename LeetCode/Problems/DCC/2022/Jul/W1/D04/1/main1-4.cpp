// 学習1回目,解説AC4

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int sig(int n) { return n * (n+1) / 2; }
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), res = 0, pslope = 0, up = 0, down = 0;
        for (int i=1; i<n; ++i) {
            int slope = (ratings[i] > ratings[i-1]) ? 1 : (ratings[i] < ratings[i-1]) ? -1 : 0;
            if ((pslope<0&&slope>=0) || (pslope>0&&slope==0)) {
                res += sig(up) + sig(down) + max(up, down);
                up = down = 0;
            }
            if (slope > 0) ++up;
            else if (slope < 0) ++down;
            else ++res;
            pslope = slope;
        }
        res += sig(up) + sig(down) + max(up, down) + 1;
        return res;
    }
};
